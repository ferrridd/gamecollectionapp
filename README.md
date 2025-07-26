# GameCollection App

A terminal-based collection of classic games written in C, featuring an interactive menu system and multiple entertaining games.

## 🎮 Features

The GameCollection App includes 9 different games and features:

1. **Special Game** - A unique tic-tac-toe variant where players must swap X and O positions
2. **Classic Tic-Tac-Toe** - Traditional 3x3 grid game
3. **Rock Paper Scissors** - The classic hand game
4. **Tapatan** - A traditional Filipino board game similar to tic-tac-toe
5. **Hangman** - Word guessing game with a 50-word dictionary
6. **Taboo Game** - Describe words without using forbidden terms
7. **Extended Tic-Tac-Toe** - Enhanced version of the classic game
8. **Who, When, Where** - A guessing game variant
9. **Online Game Recommendations** - Get random game links by category (requires internet)

## 🛠️ Prerequisites

Before building and running the GameCollection App, ensure you have the following installed:

### Required Dependencies
- **GCC Compiler** - For compiling C code
- **ncurses library** - For terminal user interface
  ```bash
  # Ubuntu/Debian
  sudo apt-get install libncurses5-dev libncurses-dev
  
  # CentOS/RHEL/Fedora
  sudo yum install ncurses-devel
  # or
  sudo dnf install ncurses-devel
  
  # macOS (with Homebrew)
  brew install ncurses
  ```

### Optional Dependencies (for enhanced visual experience)
- **figlet** - For ASCII art title display
  ```bash
  # Ubuntu/Debian
  sudo apt-get install figlet
  
  # macOS
  brew install figlet
  ```
- **lolcat** - For colorful title animation
  ```bash
  # Ubuntu/Debian
  sudo apt-get install lolcat
  
  # macOS
  brew install lolcat
  ```

## 🚀 Installation & Usage

### Building the Application
1. Clone or download the repository
2. Navigate to the project directory
3. Compile the application using the provided Makefile:
   ```bash
   make
   ```
   This creates an executable named `program`.

### Running the Game
```bash
./program
```

### Navigation
- Use **arrow keys** (↑/↓) to navigate through the game menu
- Press **Enter** to select a game
- Follow on-screen prompts for each game
- Each game offers optional instructions before starting
- After each game, you can choose to return to the main menu or exit

## 🎯 Game Descriptions

### Special Game
A unique twist on tic-tac-toe where players must move their pieces to swap the positions of X and O markers. The first player to successfully reverse all positions wins.

### Hangman
Guess the hidden word by suggesting letters. You have 5 incorrect guesses before losing. The game uses a curated wordlist of 50 common English words.

### Taboo Game
Describe words to help others guess them, but certain "banned" words cannot be used in your description. Features over 200 word cards with varying difficulty levels.

### Rock Paper Scissors
The classic game where rock crushes scissors, scissors cuts paper, and paper covers rock. Play against the computer with random selection.

### Tapatan
A traditional Filipino strategy game played on a 3x3 grid. Similar to tic-tac-toe but with a movement phase where players can move their pieces to adjacent empty spaces.

### Online Game Recommendations
Browse categorized online games including:
- Sports games (archery, billiards, soccer, basketball)
- Racing games (car driving, highway racing)
- Puzzle games (word games, logic puzzles, checkers)
- Action games (fighting, stickman battles)
- Escape games (room escape, mystery games)
- Strategy games (tower defense, civilization building)

*Note: Requires internet connection to access online recommendations.*

## 📁 Project Structure

```
gamecollectionapp/
├── introduction.c      # Main entry point
├── onGame.c           # Menu system and game selection logic
├── unique_game.c      # Special game implementation
├── tictactoe.c        # Classic tic-tac-toe
├── hangman.c          # Hangman game
├── rockpaperscissors.c # Rock paper scissors
├── tapatan.c          # Tapatan game
├── taboo.c            # Taboo word game
├── extendedTicTac.c   # Extended tic-tac-toe
├── whowhen.c          # Who/when/where game
├── online.c           # Online game recommendations
├── instructions.c     # Game instruction system
├── wordlist.txt       # Words for hangman game
├── taboo_lib.txt      # Word cards for taboo game
├── links.txt          # Online game URLs
├── Makefile           # Build configuration
└── program            # Compiled executable
```

## 🔧 Technical Details

- **Language**: C
- **UI Library**: ncurses for terminal-based interface
- **Build System**: Make
- **Platform**: Unix-like systems (Linux, macOS)
- **Network**: Basic internet connectivity check for online features

## 🐛 Troubleshooting

### Common Issues

**Compilation Errors**
- Ensure ncurses development headers are installed
- Check that GCC is properly installed and accessible

**Display Issues**
- Ensure your terminal supports ncurses
- Try resizing your terminal window if the menu appears distorted
- Some games require a minimum terminal size for proper display

**Missing Visual Effects**
- If the title doesn't display with colors/animation, install `figlet` and `lolcat`
- The games will still function without these optional dependencies

**Online Features Not Working**
- Check your internet connection
- The app performs a connectivity test to google.com before accessing online features

## 🤝 Contributing

Feel free to contribute by:
- Adding new games to the collection
- Improving existing game implementations
- Enhancing the user interface
- Adding more words to the word lists
- Fixing bugs or improving performance

## 📄 License

This project is open source and available under standard terms.

---

**Enjoy playing the GameCollection App! 🎮** 