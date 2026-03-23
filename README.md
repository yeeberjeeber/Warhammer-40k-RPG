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
   - Currently only used for storing Player Level
2. Roughly learned how inheritance works, promoted all methods that were in each enemy-specific file up to the main Enemy header file.
   - Added Enemy faction-specific methods
