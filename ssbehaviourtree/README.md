# ssbehaviourtree

I used this [site](https://www.gamedeveloper.com/programming/behavior-trees-for-ai-how-they-work) for understanding behaviour trees.

## Available
### composite
- doallselector: selector but processes all subtrees.

- doallsequence: sequence but processes all subtrees.

- selector: Returns SUCCESS upon finding a subtree that returns SUCCESS. 

- sequence: Returns FAILUE upon finding a subtree that returns FAILURE.

### decorator

- root: An entry point for all behaviour trees.


## Pending
### composite

### decorators
- inverter: Swaps SUCCESS for FAILURE and vice vera.
- succeeder: Always returns SUCCESS.
- repeater: Repeats processing the subtree.
- untilfail: Repeats until a failure occurs.