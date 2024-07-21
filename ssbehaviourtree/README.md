# ssbehaviourtree

I used this [site](https://www.gamedeveloper.com/programming/behavior-trees-for-ai-how-they-work) but made some tweaks.

## Still to add
### composite
- doallsequence: sequence but processes all subtrees.

### decorators
- inverter: Swaps SUCCESS for FAILURE and vice vera.
- succeeder: Always returns SUCCESS.
- repeater: Repeats processing the subtree.
- untilfail: Repeats until a failure occurs.