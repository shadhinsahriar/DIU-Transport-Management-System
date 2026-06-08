<div align="center">

# 🚍 DIU Transport Management System

**A console-based transport management system built in C**  
*Daffodil International University — Academic Project*

![Language](https://img.shields.io/badge/Language-C-blue?style=flat-square&logo=c)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20macOS-lightgrey?style=flat-square)
![Compiler](https://img.shields.io/badge/Compiler-GCC-orange?style=flat-square)
![Status](https://img.shields.io/badge/Status-Completed-success?style=flat-square)
![License](https://img.shields.io/badge/License-Academic%20Use-informational?style=flat-square)

</div>

---

## 📖 Overview

The **DIU Transport Management System** is a fully functional, console-driven application that digitalizes university transport operations at Daffodil International University. Built entirely in **C**, the system uses a **Doubly Linked List** as its core data structure and **file-based persistence** to store and manage real-time transport data across sessions.

The system supports four distinct user roles — **Admin, Student, Faculty, and Bus Staff** — each with their own authenticated portal and tailored feature set.

> Developed as an academic project for **Level 1, Term 3** — Structured Programming / Data Structure course.

---

## ⚙️ Tech Stack & Core Concepts

| Concept | Implementation |
|---|---|
| **Data Structure** | Doubly Linked List (`struct` nodes with `prev` / `next` pointers) |
| **Memory Management** | Dynamic allocation via `malloc()` / `free()` |
| **Data Persistence** | Binary file I/O using `.dat` files (`fread` / `fwrite`) |
| **Authentication** | Role-based login system with credential validation |
| **CRUD Operations** | Create, Read, Update, Delete across all user modules |
| **Language** | C (C99 standard) |
| **Compiler** | GCC |
| **UI Pattern** | Menu-driven console interface |

---

## 🗂️ System Architecture

```
DIU Transport Management System
│
├── 👨‍💼 Admin Portal
│   ├── Approve / Reject membership applications
│   ├── Add, remove, and manage bus staff
│   ├── Manage bus routes (add / delete)
│   ├── View complaints & generate reports
│   ├── Broadcast transport notices
│   └── Manage emergency contacts
│
├── 👨‍🎓 Student Portal
│   ├── Apply for transport membership
│   ├── View & search bus routes
│   ├── Submit complaints against staff
│   ├── Submit Bkash payment transaction ID
│   ├── View transport notices
│   └── Update personal profile
│
├── 👨‍🏫 Faculty Portal
│   ├── Register & login
│   ├── View bus schedules & routes
│   ├── Submit feedback
│   ├── Submit payment information
│   └── Update personal profile
│
└── 🚌 Bus Staff Portal
    ├── Driver / Conductor login
    ├── View assigned routes
    ├── Submit complaints against students
    └── Verify student transport validity
```

---

## 💾 File Structure & Data Persistence

All data is stored in binary `.dat` files, ensuring records are retained between sessions — functioning as a lightweight file-based database.

```
project/
├── DIU_Transport_Management_System.c   ← Main source file (single-file architecture)
├── students.dat                         ← Student records & membership data
├── faculty.dat                          ← Faculty profiles & payment info
├── stuff.dat                            ← Bus staff records
├── routes.dat                           ← Bus route configurations
├── reports.dat                          ← Complaint & feedback logs
└── notice.dat                           ← Transport notice board
```

> **Note:** `.dat` files are auto-generated on first run. Do not delete them during active use.

---

## 🚀 Getting Started

### Prerequisites

- GCC compiler installed (`gcc --version` to verify)
- Terminal / Command Prompt

### Compile

```bash
gcc DIU_Transport_Management_System.c -o transport
```

### Run

```bash
# Windows
transport.exe

# Linux / macOS
./transport
```

### Default Admin Credentials

```
ID       : admin.diu
Password : admin123
```

> ⚠️ These credentials are for academic demonstration only. Change them before any real-world deployment.

---

## ✨ Key Features at a Glance

- **Role-Based Access Control (RBAC)** — Four isolated user portals with separate authentication
- **Doubly Linked List** — Efficient insertion, deletion, and traversal of all records in memory
- **Persistent Storage** — Data survives program termination via binary file serialization
- **Membership Workflow** — Full application → approval → activation pipeline
- **Payment Tracking** — Bkash transaction ID submission and verification
- **Complaint System** — Bidirectional complaint submission (student ↔ staff)
- **Transport Notices** — Admin-broadcast notice board accessible to all users
- **Route Management** — Dynamic add/remove of bus routes with search functionality

---

## 📚 What I Learned

This project was a hands-on exercise in systems-level programming and software design:

- Implementing a **doubly linked list** from scratch with pointer manipulation
- Designing a **role-based authentication** system without a database
- Using **file I/O** as a persistence layer (a precursor to real database integration)
- Structuring a large single-file C program with logical modularity
- Thinking in terms of **data flow** and **user workflows**

---

## 🔮 Future Roadmap

- [ ] GUI version using GTK or Qt
- [ ] MySQL / SQLite database integration
- [ ] Real-time GPS bus tracking
- [ ] QR-code-based digital tickets
- [ ] Web dashboard (React + REST API)
- [ ] Mobile application (Android / iOS)

---

## 🎓 Academic Information

| Field | Detail |
|---|---|
| **University** | Daffodil International University (DIU) |
| **Level / Term** | Level 1, Term 3 |
| **Course** | Structured Programming / Data Structure |
| **Project Type** | Academic Group Project |

---

## 👨‍💻 Author

**Sahriar Ekhlas**  
Computer Science Student — Daffodil International University  
GitHub: [@shadhinsahriar](https://github.com/shadhinsahriar)

---

<div align="center">

*Built with C — no frameworks, no shortcuts, just fundamentals.*

</div>
