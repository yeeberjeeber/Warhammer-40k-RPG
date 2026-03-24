# Warhammer 40,000 Roguelike
Yeah the repo has RPG in it, things happen.<br/>
<br/>

# Technologies Used:
C++ <br/>
<br/>
Mainly used for personal learning in developing an actual C++ project.<br/>
<br/>

# Lessons Learned:
1. How small `uint8_t` actually was, tried to declare variables (e.g. level) using said type, only for the program to return 1 after multiple tries.
   - Changed all `uint8_t` type declarations to `uint16_t` instead to avoid bugs

<br/>

2. Roughly learned how inheritance works, promoted all methods that were in each enemy-specific file up to the main Enemy header file.
   - Added Enemy faction-specific methods
   - `virtual`, `override` and pointers are essential to inheritance
      - Without the above, I would need to redeclare code for each specific enemy
      - Pointers are essential to prevent object slicing
      - When we declare `virtual` during runtime, for each object with virtual methods, a hidden vtable that stores addresses of actual methods for that class is created by the compiler
      - e.g. When we call method `e->attack();`, the compiler looks at the vtable pointer, find the address of `attack()` and call it

<br/>

3. Learned how to spawn multiple enemies
   - Create a vector with a unique pointer -> `unique_ptr` so that it does not require deallocation once the function ends
   - Populate said vector with randomly generated amount of enemies
