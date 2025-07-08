# 🃏 Unreal Engine 5.6 Card-Battler – Blueprint Framework

### 📈 Progress  **12 / 16 steps complete (≈ 75 %)**

| ✔ | # | 🎯 Goal | 🔑 Blueprint / Asset Types | 🧩 What You Build |
|:-:|---|---------|---------------------------|------------------|
| ✅ | 0 | **Clean project** | Blank **C++** template, single **BP_/** folder | Turn on *Enhanced Input*, *Data Assets*, *Gameplay Tags*, *SaveGame* in **Plugins**. <br/>*Docs → Project Setup, Plugins* |
| ✅ | 1 | **Pure data first** | `UStruct`, `DataTable`, `PrimaryDataAsset` | `FCardData`, `FStatusEffectData`, `FArtifactData`, `FEncounterNodeData` – fields only, no logic. Easy tuning & CSV import. <br/>*Docs → UStructs & Data Tables* |
| ✅ | 2 | **Component actors** | `UCardComponent`, `UStatusEffectComponent`, `UAttackPatternComponent`, `UCombatStatsComponent` | Build pawns/enemies/cards by stacking components → reusable & testable. <br/>*Docs → Actor Components* |
| ✅ | 3 | **Card lifecycle** | `BP_CardActor` (world) + `BP_CardWidget` (UI) | States: *DrawPile → Hand → Queue → Grave*. Fire events: `OnDraw`, `OnPlay`, `OnResolve`, `OnDiscard`. <br/>*Docs → Gameplay Framework* |
| ✅ | 4 | **Turn manager** | `BP_CombatManager` | Controls loop: *StartTurn → Player → Enemy → EndTurn*. Tracks rounds, energy, win/loss. <br/>*Docs → Timers & Tick* |
| ✅ | 5 | **Event bus** | `UEventRouter` (GameMode subobject) | Publish/Subscribe: e.g. `"CardPlayed"`, `"DamageTaken"`; loose coupling. <br/>*Docs → Blueprint Dispatchers* |
| ✅ | 6 | **Rich UI** | `BP_HUD_Widget` root + Hand, DrawPile, Discard, Tooltip, EnemyIntent, StatusBars | Widgets listen to the event bus; use Widget Animations for flashes. <br/>*Docs → UMG Basics, Binding* |
| ✅ | 7 | **Enemy AI** | `UAttackPatternComponent` + DataTable | Rows: Ability, Weight, RepeatLimit, Tag. Chooses next ability each Enemy phase; broadcasts `"SelectedIntent"`. <br/>*Docs → Data-Driven AI* |
| ✅ | 8 | **Rewards** | `BP_RewardManager` (GameMode sub-object) | Pools cards/artifacts by rarity; `GiveRewards()` spawns pick screen. <br/>*Docs → Random Streams, Gameplay Tags* |
| ✅ | 9 | **World map** | `ANodeActor` + `UNodeMapWidget` | Place nodes in an Overview level. Click → travel, save run state, load combat level. <br/>*Docs → Level Streaming* |
| ✅ | 10 | **Shop & story** | `BP_ShopWidget`, `BP_StoryEventWidget` | Driven from `NodeData` type. Story rows hold snippet + choices in DataTable. <br/>*Docs → UMG Dynamic UI* |
| ✅ | 11 | **Save / Load** | `USaveGame_RunState` + `BP_SaveSubsystem` | Store deck, artifacts, HP, gold, visited nodes, seed. Autosave after every node. <br/>*Docs → SaveGame Object* |
| ⬜ | 12 | **Level swap** | Combat Level ↔ Map Level | GameMode handles `OpenLevel()`, clears old UI/event binds. <br/>*Docs → OpenLevel, GameInstance* |
| ⬜ | 13 | **Example content** | CSV → DataTable import | Add 20 cards, 5 artifacts, 3 status effects per rarity. Use public-domain art. <br/>*Docs → Data Import* |
| ⬜ | 14 | **QA & balance** | Editor Utility Widget “BalanceBoard” | Show live stats: dmg/energy, draw odds. Tweak numbers directly in DataTables. <br/>*Docs → Editor Utility Widgets* |
| ⬜ | 15 | **Package & hand-off** | Project Settings → Packaging | Check cooked assets, size, redirects. Ship this README so new folks can jump in anywhere. <br/>*Docs → Packaging Projects* |

## Using the New Components

* **UCardComponent** – attach to card actors and trigger the dispatcher events when the card is drawn or played.
* **UStatusEffectComponent** – keeps active effects; call `ApplyStatus` or `ApplyStatusByTag` to add stacks.
* **UAttackPatternComponent** – link a DataTable of `FCardPatternData` and call `PickNextCard()` for weighted AI. The component broadcasts `OnIntentSelected` with the chosen card.
* **UCombatStatsComponent** – stores health, block and energy. `ApplyDamage()` notifies the global `UEventRouter`.
* **ANodeActor** – place nodes in map levels, assign `NodeData` and connect neighbours via the `Neighbours` array. Use `GetNeighbours()` in Blueprints.
* **UNodeMapWidget** – call `InitWithNodes` with all node actors and handle `OnNodeSelected` when the player picks a destination.
* **AGameHUD** – custom HUD that creates your `BP_HUD_Widget` at begin play. Set `BP_GameHUD` as the HUD Class in `BP_CoreGameMode`.

## Visual Models & Animations

The new `FCardVisualData` struct describes the presentation for any card‑spawned actor.  It holds optional fields for a sprite, flipbook or skeletal mesh plus five animation slots:

* `IdleAnimation`
* `AttackAnimation`
* `DefendAnimation`
* `WalkAnimation`
* `RetreatAnimation`

When importing a CSV to a DataTable, reference these assets using the columns `Visual.Sprite`, `Visual.Flipbook`, `Visual.SkeletalMesh` and the corresponding animation columns.  Each row’s values are assigned to the card’s `FCardData::Visual` field.

`UCardVisualComponent` reads this struct on `BeginPlay`.  It automatically spawns the appropriate component type – `USkeletalMeshComponent`, `UPaperFlipbookComponent` or `UPaperSpriteComponent` – attaches it to the card and plays the idle animation.  Blueprint functions `PlayAttack`, `PlayDefend`, `PlayWalk`, `PlayRetreat` and `PlayIdle` wrap the actual animation calls.

Extend the component in Blueprints if you need custom behaviour (e.g. particles or sounds on certain animations).  Create a child blueprint of `UCardVisualComponent`, override the animation functions or add new ones and set your subclass on the actor instead of the base component.

---

![image](https://github.com/user-attachments/assets/0b38587e-b1c7-47f9-b1d1-04046d4f768e)


![image](https://github.com/user-attachments/assets/d83d6c78-de2d-4096-b29a-980d0558ac7b)



![image](https://github.com/user-attachments/assets/7f51c5b1-8575-4518-81e4-2a9bd18cf65d)
