# ✈️ Airport & Airplane Management System  

## 📌 Project Overview  
This project is a **final assignment for SAS YouCode**.  
It is a **C program** that manages an airport and its airplanes.  

The system allows users to:  
- Add an airport and its airplanes  
- Display airplanes  
- Modify airplane details  
- Delete airplanes  
- Search airplanes (by ID or model)  
- Sort airplanes (by capacity or model name)  
- Show statistics (availability, maintenance, flights, max & min capacity)  

The program uses a **menu-driven interface** to interact with the user.  

---

## 🗂️ Project Structure  

```
📂 Project Folder
 ├── main.c        # Entry point of the program (menu system)
 ├── functions.c   # Implementation of all functions
 ├── header.h      # Structures, constants, and function prototypes
 └── README.md     # Project documentation
```

- **main.c** → Handles the program loop and menu.  
- **functions.c** → Implements all functionalities.  
- **header.h** → Defines structures (`Avions`, `aerport`) and declares functions.  

---

## ⚙️ Features  

✅ Add an airport  
✅ Add one or multiple airplanes  
✅ Display all airplanes  
✅ Modify airplane information  
✅ Delete an airplane by ID  
✅ Search airplanes (by ID or by model)  
✅ Sort airplanes (by capacity or alphabetical model)  
✅ Show statistics (availability, maintenance, flight, largest and smallest capacity)  

---

## 🖥️ Compilation & Execution  

1. Open a terminal in the project folder.  
2. Compile the program with:  

```bash
gcc main.c functions.c -o airport
```

3. Run the program:  

```bash
./airport
```

---

## 📊 Example of Menu  

```
-------------------------------------------------------
          Welcome To Casablanca Airport                
--------------------------------------------------------

====== MENU ======
1. Ajouter avion(s)
2. Afficher avions
3. Modifier avion
4. Supprimer avion
5. Rechercher avion par ID
6. Rechercher avion par modele
7. Trier avions par capacite
8. Trier avions par modele (alphabetique)
9. Statistiques
0. Quitter
==================
Votre choix:
```

---

## 🚀 Future Improvements  

- Save & load data from a file (persistent storage)  
- Support multiple airports  
- Improve input validation  

---

## 👨‍💻 Author  

This project was developed as a **final project for SAS YouCode**.  
