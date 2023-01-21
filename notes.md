## Map parsing

### Settings
- [X] Line can start with "#" (comments)
	- jump to next line.
- [X] Character is one of the following: NO, SO, WE, EA, F, C
	- [X] Orientations: path must be valid.
	- [ ] COLORS: 3 numbers between 0-255 (hexadecimal too?)
		- [X] Colors can be separated by spaces or commas.
		- [ ] Error check:
			- [X] Number not inbetween 0-255;
			- [ ] Non-digits.
			- [ ] Negative numbers;

### Error checking:
- [ ] Map accepts only 8 possible characters: space, tab, 0 (empty space), 1 (wall) and only one of following: N, S, E, or W (player's start position and orientation).
- [ ] Map must be surrounded by walls.
- [ ] Map content is at the end of the file. Other elements can be in any other.
- [ ]
