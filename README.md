# 2048 Game in C

A terminal-based implementation of the popular **2048 puzzle game**, written in **C** and designed with efficient use of **data structures**.  

The project demonstrates concepts of **arrays, dynamic memory, matrices, and game logic handling** in C.

---

## 🎮 Game Rules
- The game is played on a 4x4 grid.
- Use W,A,S,D keys to move the tiles.
- When two tiles with the same number collide, they **merge into one** with their sum.
- The goal is to create the **2048 tile**.
- The game ends when:
  - You reach 2048 (**Win**), or  
  - No moves are possible (**Game Over**).

---

## 🛠 Features
- Fully playable in the terminal.
- Randomized tile generation after each move.
- Detects win/loss state.
- Implementation focused on data structure usage.

---

## 📂 Project Structure
2048/<br>
│-- 2048.c # Complete game implementation<br>
│-- README.md # Project documentation<br>

---

## ⚙️ Data Structures Used
- **2D Array (Matrix):** to represent the game board.
- **1D Array:** to manipulate game state.
- **Functions & Modular Code:** for move handling, tile merging, and board updates.

---

## 🚀 How to Run
1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/2048-c-game.git
   cd 2048-c-game

2. Compile the program: <br>
gcc 2048.c -o 2048

3. Run the game:<br>
./2048

📚 Learning Outcomes <br>
Applying data structures (arrays, structs) in a real project. <br>
Handling matrix manipulations for game logic.<br>
Improving problem-solving and modular coding skills in C.<br>
Understanding basic game loop and state management.<br>

📄 License<br>
This project is licensed under the MIT License – see the LICENSE
 file for details.
