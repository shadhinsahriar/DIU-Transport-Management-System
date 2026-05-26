#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user {
    char name[50];
    char id[30];
    char designation[50];
    char department[20];
    char phone[15];
    char email[50];
    char password[20];
    int role;//flag
    int approve;//flag
    int payStatus;//flag
    char bkashTrxID[30];
    struct user *pre;
    struct user *next;
};

struct employ{
    char name[50];
    char id[30];
    int nationalID;
    char phone[15];
    int driver;//flag
    int drivingLincence;
    char password[20];
    struct employ *pre;
    struct employ *next;
};

struct busRoute {
    char busID[20];
    char origin[50];
    char destination[50];
    char driverID[30];
    char time[20];
    struct busRoute *pre;
    struct busRoute *next;
};

struct report {
    char type[20];
    char senderID[30];
    char targetID[30];   
    char message[400];
    struct report *pre;
    struct report *next;
};

struct user *student = NULL;
struct user *faculty = NULL;
struct employ *stuff = NULL;
struct busRoute *routeList = NULL;
struct report *reportList = NULL; 

char transportNotice[500] = "No new transport/fare notice available.";

void saveData() {
    FILE *fp;

    fp = fopen("students.dat", "w");
    struct user *u = student;
    while(u) {
        fprintf(fp, "%s|%s|%s|%s|%s|%s|%s|%d|%d|%d|%s\n", u->name, u->id, u->designation, u->department, u->phone, u->email, u->password, u->role, u->approve, u->payStatus, u->bkashTrxID);
        u = u->next;
    }
    fclose(fp);

    fp = fopen("faculty.dat", "w");
    u = faculty;
    while(u) {
        fprintf(fp, "%s|%s|%s|%s|%s|%s|%s|%d|%d|%d|%s\n", u->name, u->id, u->designation, u->department, u->phone, u->email, u->password, u->role, u->approve, u->payStatus, u->bkashTrxID);
        u = u->next;
    }
    fclose(fp);

    fp = fopen("stuff.dat", "w");
    struct employ *e = stuff;
    while(e) {
        fprintf(fp, "%s|%s|%d|%s|%d|%d|%s\n", e->name, e->id, e->nationalID, e->phone, e->driver, e->drivingLincence, e->password);
        e = e->next;
    }
    fclose(fp);

    fp = fopen("routes.dat", "w");
    struct busRoute *r = routeList;
    while(r) {
        fprintf(fp, "%s|%s|%s|%s|%s\n", r->busID, r->origin, r->destination, r->driverID, r->time);
        r = r->next;
    }
    fclose(fp);

    fp = fopen("reports.dat", "w");
    struct report *rp = reportList;
    while(rp) {
        fprintf(fp, "%s|%s|%s|%s\n", rp->type, rp->senderID, rp->targetID, rp->message);
        rp = rp->next;
    }
    fclose(fp);

    fp = fopen("notice.dat", "w");
    if(fp) {
        fprintf(fp, "%s", transportNotice);
        fclose(fp);
    }
}

void loadData() {
    FILE *fp;
    char line[600];

    fp = fopen("students.dat", "r");
    if(fp) {
        while(fgets(line, sizeof(line), fp)) {
            struct user *n = (struct user*)malloc(sizeof(struct user));
            sscanf(line, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%d|%d|%d|%[^\n]", n->name, n->id, n->designation, n->department, n->phone, n->email, n->password, &n->role, &n->approve, &n->payStatus, n->bkashTrxID);
            n->next = NULL; n->pre = NULL;
            if(!student) student = n;
            else { struct user *i = student; while(i->next) i = i->next; i->next = n; n->pre = i; }
        }
        fclose(fp);
    }

    fp = fopen("faculty.dat", "r");
    if(fp) {
        while(fgets(line, sizeof(line), fp)) {
            struct user *n = (struct user*)malloc(sizeof(struct user));
            sscanf(line, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%d|%d|%d|%[^\n]", n->name, n->id, n->designation, n->department, n->phone, n->email, n->password, &n->role, &n->approve, &n->payStatus, n->bkashTrxID);
            n->next = NULL; n->pre = NULL;
            if(!faculty) faculty = n;
            else { struct user *i = faculty; while(i->next) i = i->next; i->next = n; n->pre = i; }
        }
        fclose(fp);
    }

    fp = fopen("stuff.dat", "r");
    if(fp) {
        while(fgets(line, sizeof(line), fp)) {
            struct employ *ne = (struct employ*)malloc(sizeof(struct employ));
            sscanf(line, "%[^|]|%[^|]|%d|%[^|]|%d|%d|%[^\n]", ne->name, ne->id, &ne->nationalID, ne->phone, &ne->driver, &ne->drivingLincence, ne->password);
            ne->next = NULL; ne->pre = NULL;
            if(!stuff) stuff = ne;
            else { struct employ *i = stuff; while(i->next) i = i->next; i->next = ne; ne->pre = i; }
        }
        fclose(fp);
    }

    fp = fopen("routes.dat", "r");
    if(fp) {
        while(fgets(line, sizeof(line), fp)) {
            struct busRoute *n = (struct busRoute*)malloc(sizeof(struct busRoute));
            sscanf(line, "%[^|]|%[^|]|%[^|]|%[^|]|%[^\n]", n->busID, n->origin, n->destination, n->driverID, n->time);
            n->next = NULL; n->pre = NULL;
            if(!routeList) routeList = n;
            else { struct busRoute *i = routeList; while(i->next) i = i->next; i->next = n; n->pre = i; }
        }
        fclose(fp);
    }

    fp = fopen("reports.dat", "r");
    if(fp) {
        while(fgets(line, sizeof(line), fp)) {
            struct report *n = (struct report*)malloc(sizeof(struct report));
            sscanf(line, "%[^|]|%[^|]|%[^|]|%[^\n]", n->type, n->senderID, n->targetID, n->message);
            n->next = NULL; n->pre = NULL;
            if(!reportList) reportList = n;
            else { struct report *i = reportList; while(i->next) i = i->next; i->next = n; n->pre = i; }
        }
        fclose(fp);
    }

    fp = fopen("notice.dat", "r");
    if(fp) {
        fgets(transportNotice, sizeof(transportNotice), fp);
        fclose(fp);
    }
}

void SearchIDValidity() {
    char searchID[30];
    printf("\nEnter ID to check validity: ");
    scanf("%s", searchID);
    getchar();

    struct user *u = student;
    int found = 0;
    while(u) {
        if(strcmp(u->id, searchID) == 0) {
            printf("\n--- Student Found ---\nID: %s | Name: %s\nStatus: %s\nPayment: %s\nTrxID: %s\n", 
            u->id, u->name, u->approve ? "Approved" : "Pending", u->payStatus ? "Paid" : "Unpaid", u->bkashTrxID);
            found = 1; break;
        }
        u = u->next;
    }
    if(!found) {
        u = faculty;
        while(u) {
            if(strcmp(u->id, searchID) == 0) {
                printf("\n--- Faculty Found ---\nID: %s | Name: %s\nStatus: %s\nPayment: %s\nTrxID: %s\n", 
                u->id, u->name, u->approve ? "Approved" : "Pending", u->payStatus ? "Paid" : "Unpaid", u->bkashTrxID);
                found = 1; break;
            }
            u = u->next;
        }
    }
    if(!found) printf("ID not found in system.\n");
}

void SubmitBkashPayment(struct user *u) {
    printf("\n--- BKASH PAYMENT SUBMISSION ---\n");
    printf("Enter Bkash Transaction ID: ");
    scanf(" %[^\n]", u->bkashTrxID);
    u->payStatus = 1;
    printf("Payment record saved and flagged as 'Paid'.\n");
}

void ManageNotice(int mode) {
    if (mode == 1) { 
        printf("\nEnter New Notice: ");
        scanf(" %[^\n]", transportNotice);
        printf("Notice Updated!\n");
    } else { 
        printf("\n\033[1m<<<< TRANSPORT & FARE NOTICE >>>>\033[0m\n");
        printf("------------------------------------\n");
        printf("%s\n", transportNotice);
        printf("------------------------------------\n");
    }
}

void addReport(char type[], char sID[], char tID[]) {
    struct report *newNode = (struct report*)malloc(sizeof(struct report));
    if (newNode == NULL) {
        printf("Memory error!\n");
        return;
    }

    strcpy(newNode->type, type);
    strcpy(newNode->senderID, sID); 
    strcpy(newNode->targetID, tID);

    printf("Enter the details of your %s: ", type);
    scanf(" %[^\n]", newNode->message);

    newNode->pre = NULL;
    newNode->next = NULL;

    if (reportList == NULL) {
        reportList = newNode;
    } else {
        struct report *temp = reportList;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
        newNode->pre = temp;
    }
    printf("\nSuccess! Report from ID: %s has been saved.\n", sID);
}

void removeReport(struct report *i) {
    if (i->pre == NULL && i->next == NULL) {
        reportList = NULL;
    } else if (i->pre == NULL) {
        reportList = i->next;
        i->next->pre = NULL;
    } else if (i->next == NULL) {
        i->pre->next = NULL;
    } else {
        i->pre->next = i->next;
        i->next->pre = i->pre;
    }
    free(i);
    printf("Record removed from system.\n");
}

void ViewReportsAdmin() {
    if (reportList == NULL) {
        printf("\nNo complaints or issues found.\n");
        return;
    }

    struct report *i = reportList;
    while (i != NULL) {
        struct report *tempNext = i->next; 
        
        printf("\n--- %s Details ---", i->type);
        printf("\nFrom ID   : %s", i->senderID);
        if (strcmp(i->targetID, "N/A") != 0) {
            printf("\nAgainst ID: %s", i->targetID);
        }
        printf("\nMessage   : %s", i->message);
        printf("\n-------------------------");

        printf("\n1. Next Record\n2. Delete this record\n3. Exit\nChoice: ");
        int choice;
        scanf("%d", &choice);
        getchar();

        if (choice == 2) {
            removeReport(i);
        } else if (choice == 3) {
            return;
        }
        i = tempNext;
    }
}


void UpdateProfile(struct user *head, char currentID[]) {
    struct user *i = head;
    while(i != NULL && strcmp(i->id, currentID) != 0) i = i->next;
    
    if(i == NULL) return;

    printf("\n--- Update Profile (%s) ---\n", i->name);
    printf("Enter New Phone: ");
    scanf(" %[^\n]", i->phone);
    printf("Enter New Password: ");
    scanf(" %[^\n]", i->password);
    printf("Profile Updated Successfully!\n");
}


void ShowAllUsers() {
    printf("\n--- Registered Faculty members ---\n");
    struct user *f = faculty;
    if(!f) printf("No faculty records.\n");
    while(f) {
        if(f->approve == 1) printf("ID: %s | Name: %s | Dept: %s\n", f->id, f->name, f->department);
        f = f->next;
    }

    printf("\n--- Registered Student members ---\n");
    struct user *s = student;
    if(!s) printf("No student records.\n");
    while(s) {
        if(s->approve == 1) printf("ID: %s | Name: %s | Dept: %s\n", s->id, s->name, s->department);
        s = s->next;
    }
}

struct user* insertUser(struct user *head, int role) {
    struct user* temp = (struct user*)malloc(sizeof(struct user));
    
    if (temp == NULL) return head;

    temp->role = role;

    if (role == 1) {
        printf("\n--- Student Registration ---\n");
    } else {
        printf("\n--- Faculty Registration ---\n");
    }
    
    printf("Name : ");
    scanf(" %[^\n]", temp->name);

    printf("ID   : ");
    scanf(" %[^\n]", temp->id);

    if (role == 1) {
        printf("Year/Semester : ");
    } else {
        printf("Designation : ");
    }
    scanf(" %[^\n]", temp->designation);

    printf("Department : ");
    scanf(" %[^\n]", temp->department);

    printf("Phone : ");
    scanf(" %[^\n]", temp->phone);

    printf("Email : ");
    scanf(" %[^\n]", temp->email);

    printf("Password : ");
    scanf(" %[^\n]", temp->password);

    temp->approve = 0;
    temp->payStatus = 0; 
    strcpy(temp->bkashTrxID, "N/A"); 
    temp->pre = NULL;
    temp->next = NULL;


    if (head == NULL) {
        head = temp;
    } else {
        struct user *i = head;
        while (i->next != NULL) i = i->next;
        i->next = temp;
        temp->pre = i;
    }

    if (role == 1) {
        printf("\nStudent application received.\n");
    } else {
        printf("\nFaculty application received.\n");
    }
            
    return head; 
}

void deleteUser(char ID[50] , int n){
    struct user *i = NULL;

    if(n == 1) i = student;
    else if(n == 2) i = faculty;
    else return;

    while(i != NULL && strcmp(i->id, ID) != 0){
        i = i->next;
    }

    if(i == NULL){
        printf("The user not found\n");
        return;
    }

    if(i->pre == NULL && i->next == NULL){
        if(n == 1) student = NULL;
        else if(n == 2) faculty = NULL;
    }
    else if(i->pre == NULL){
        if(n == 1) student = i->next;
        else if(n == 2) faculty = i->next;
        i->next->pre = NULL;
    }
    else if(i->next == NULL){
        i->pre->next = NULL;
    }
    else{
        i->pre->next = i->next;
        i->next->pre = i->pre;
    }

    free(i);
    printf("The applicant has been deleted successfully\n");
}

void addStuff(int driver){
    struct employ* temp = (struct employ*)malloc(sizeof(struct employ));

    printf("Name : ");
    scanf(" %[^\n]", temp->name);

    printf("ID : ");
    scanf(" %[^\n]", temp->id);

    printf("National ID : ");
    scanf("%d", &temp->nationalID);
    getchar();

    printf("Phone : ");
    scanf(" %[^\n]", temp->phone);

    printf("Password : ");
    scanf(" %[^\n]", temp->password);

    temp->driver = driver;

    if(driver != 0){
        printf("Driving Licence No : ");
        scanf("%d", &temp->drivingLincence);
        getchar();
    } else {
        temp->drivingLincence = 0;
    }

    temp->pre = NULL;
    temp->next = NULL;

    if(stuff == NULL){
        stuff = temp;
        printf("\nStaff has been added\n");
        return;
    }

    struct employ *i = stuff;
    while(i->next != NULL){
        i = i->next;
    }
    i->next = temp;
    temp->pre = i;
    printf("\nStaff has been added\n");
}

void deleteStuff(){
    char ID[50];
    printf("Enter Staff ID to delete: ");
    scanf(" %[^\n]", ID);

    if(stuff == NULL){
        printf("No staff available\n");
        return;
    }

    struct employ *i = stuff;

    while(i != NULL && strcmp(i->id, ID) != 0){
        i = i->next;
    }

    if(i == NULL){
        printf("Staff not found\n");
        return;
    }

    if(i->pre == NULL && i->next == NULL){
        stuff = NULL;
    } else if(i->pre == NULL){
        stuff = i->next;
        i->next->pre = NULL;
    } else if(i->next == NULL){
        i->pre->next = NULL;
    } else {
        i->pre->next = i->next;
        i->next->pre = i->pre;
    }

    free(i);
    printf("Staff has been deleted successfully\n");
}

void displayApproval(struct user *i, int n){
    while(i != NULL){
        struct user *nextNode = i->next;

        if(i->approve == 0){
            printf("Name       : %s\n", i->name);
            printf("ID         : %s\n", i->id);
            printf("Department : %s\n", i->department);
            printf("Phone      : %s\n", i->phone);
            printf("\n");

            printf("Do you want to approve?\n");
            int option;
            printf("1. Approve\n2. Reject\n");
            scanf("%d", &option);
            getchar();

            if(option == 1){
                i->approve = 1;
            }
            else if(option == 2){
                deleteUser(i->id ,n);
            }
        }

        i = nextNode;
    }
}

void DisplayBusRoutes(){
    if(routeList == NULL){
        printf("No bus routes available\n");
        return;
    }

    struct busRoute *i = routeList;
    printf("\n----- All Bus Routes -----\n");

    while(i != NULL){
        printf("Bus ID      : %s\n", i->busID);
        printf("Origin      : %s\n", i->origin);
        printf("Destination : %s\n", i->destination);
        printf("Driver ID   : %s\n", i->driverID);
        printf("Time        : %s\n", i->time);
        printf("---------------------------\n");
        i = i->next;
    }
}


void Specific_Bus_Schedule(struct busRoute *head) {
    char route[50];
    struct busRoute *i = head;
    int found = 0;

    printf("\n----- Search Specific Bus Route -----\n");
    printf("Enter Origin or Destination to filter: ");
    
    scanf(" %[^\n]", route);

    printf("\n--- Results ---\n");
    while (i != NULL) {
        if (strcmp(i->origin, route) == 0 || strcmp(i->destination, route) == 0) {
            printf("Bus ID      : %s\n", i->busID);
            printf("Origin      : %s\n", i->origin);
            printf("Destination : %s\n", i->destination);
            printf("Driver ID   : %s\n", i->driverID);
            printf("Time        : %s\n", i->time);
            printf("---------------------------\n");
            found = 1;
        }
        i = i->next; 
    }

    if (!found) {
        printf("No buses found for route: %s\n", route);
    }
}

void Check_My_Schedule(char currentID[]) {
    struct busRoute *i = routeList;
    int found = 0;
    printf("\n----- Your Assigned Schedule -----\n");
    while (i != NULL) {
        if (strcmp(i->driverID, currentID) == 0) {
            printf("Bus ID      : %s\n", i->busID);
            printf("Origin      : %s\n", i->origin);
            printf("Destination : %s\n", i->destination);
            printf("Time        : %s\n", i->time);
            printf("---------------------------\n");
            found = 1;
        }
        i = i->next;
    }
    if (!found) {
        printf("You have no bus assigned to your ID (%s) currently.\n", currentID);
    }
}

void AddBusRoute(){
    struct busRoute *newRoute = (struct busRoute*)malloc(sizeof(struct busRoute));

    printf("Bus ID : ");
    scanf(" %[^\n]", newRoute->busID);

    printf("Origin : ");
    scanf(" %[^\n]", newRoute->origin);

    printf("Destination : ");
    scanf(" %[^\n]", newRoute->destination);

    printf("Driver ID : ");
    scanf(" %[^\n]", newRoute->driverID);

    printf("Time : ");
    scanf(" %[^\n]", newRoute->time);

    newRoute->pre = NULL;
    newRoute->next = NULL;

    if(routeList == NULL){
        routeList = newRoute;
        printf("\nBus route added successfully\n");
        return;
    }

    struct busRoute *i = routeList;
    while(i->next != NULL) i = i->next;
    i->next = newRoute;
    newRoute->pre = i;

    printf("\nBus route added successfully\n");
}

void RemoveBusRoute(){
    if(routeList == NULL){
        printf("No bus routes available\n");
        return;
    }

    char busID[20];
    printf("Enter Bus ID to remove route: ");
    scanf(" %[^\n]", busID);

    struct busRoute *i = routeList;

    while(i != NULL && strcmp(i->busID, busID) != 0) i = i->next;

    if(i == NULL){
        printf("Bus route not found\n");
        return;
    }

    if(i->pre == NULL && i->next == NULL) routeList = NULL;
    else if(i->pre == NULL){
        routeList = i->next;
        i->next->pre = NULL;
    }
    else if(i->next == NULL){
        i->pre->next = NULL;
    }
    else {
        i->pre->next = i->next;
        i->next->pre = i->pre;
    }

    free(i);
    printf("Bus route removed successfully\n");
}

void StuffSellection(){
    int option;
    while(1){
        printf("\033[1m     DRIVER OR CONDUCTOR     \033[0m\n");
        printf("===========================\n\n");

        printf("1. Driver\n");
        printf("2. Conductor\n");
        printf("0. Exit\n");
        printf("\n---------------------------\n");

        printf("Enter Your Choice: ");
        scanf("%d", &option);
        getchar();

        if(option == 1){
            addStuff(1);
            return;
        }else if(option == 2){
            addStuff(0);
            return;
        }else if(option == 0){
            return;
        }else{
            printf("Invalid option!! Try again.\n");
        }
    }
}

void ViewNewApplicants(){
    if(student == NULL && faculty == NULL){
        printf("There are no applications\n");
        return;
    }

    if(student != NULL){
        printf("Student Applications\n");
        displayApproval(student, 1);
    }

    if(faculty != NULL){
        printf("Faculty Applications\n");
        displayApproval(faculty, 2);
    }
}

void deleteUseMenu(){
    int option;
    char id[50];

    while (1) {
        printf("\n\033[1m    <<<< CANCEL USER STATUS >>>>\033[0m\n");
        printf("===========================\n");

        printf("1. Cancel Faculty Membership\n");
        printf("2. Cancel Student Membership\n");
        printf("0. Back to Main Menu\n");
        printf("\n---------------------------\n");

        printf("Enter Your Choice: ");
        scanf("%d", &option);
        getchar(); 

        if(option == 1){
            printf("\nEnter Faculty ID to Delete: ");
            scanf(" %[^\n]", id);
            deleteUser(id, 2);
        }
        else if(option == 2){
            printf("\nEnter Student ID to Delete: ");
            scanf(" %[^\n]", id);
            deleteUser(id , 1);
        }
        else if(option == 0){
            printf("Returning to Main Menu...\n");
            break;
        }
        else{
            printf("Invalid option! Please try again.\n");
        }
    }
}

void Bus_Fare_Info(int n) {
    static char info[300] = "";   
    int option;

    if (n == 1) {
        while (1) {
            printf("\n\033[1m    <<<< BUS FARE MENU >>>>\033[0m\n");
            if (strlen(info) != 0)
                printf("Current Info: %s\n", info);
            else
                printf("No info available.\n\n");

            printf("1. Update Info\n");
            printf("2. Back\n");
            printf("Choose option: ");
            scanf("%d", &option);
            getchar(); 

            if (option == 1) {
                printf("Enter new bus fare info: ");
                scanf(" %[^\n]", info);
            }
            else if (option == 2) {
                return;   
            }
            else {
                printf("Invalid choice.\n");
            }
        }
    }
    else if (n == 2) {
        printf("\n\033[1m    <<<< BUS FARE INFO >>>>\033[0m\n");
        if (strlen(info) == 0) {
            printf("No notice available.\n");
        } else {
            printf("Notice: %s\n", info);
        }
        printf("Press any key to go back...\n");
        getchar();
    }
}

void Emergency_Contact(int n) {
    static char contacts[300] = "Transport: 0123456789, Security: 0987654321, Medical: 01700000000"; 
    int option;

    if (n == 1) { 
        while (1) {
            printf("\n\033[1m    <<<< EMERGENCY CONTACT MANAGEMENT >>>>\033[0m\n");
            if (strlen(contacts) != 0)
                printf("Current Contacts: %s\n", contacts);
            else
                printf("No contacts set.\n\n");

            printf("1. Update Contacts\n");
            printf("2. Back\n");
            printf("Choose option: ");
            scanf("%d", &option);
            getchar(); 

            if (option == 1) {
                printf("Enter new emergency contacts: ");
                scanf(" %[^\n]", contacts);
                printf("Contacts updated successfully!\n");
            }
            else if (option == 2) {
                return;   
            }
            else {
                printf("Invalid choice.\n");
            }
        }
    }
    else if (n == 2) {
        printf("\n\033[1m    <<<< EMERGENCY CONTACTS >>>>\033[0m\n");
        if (strlen(contacts) == 0) {
            printf("No emergency contacts available.\n");
        } else {
            printf("%s\n", contacts);
        }
        printf("\nPress Enter to go back...");
        getchar();
    }
}


void Admin_Menu() {
    int option;
    while(1) {
        printf("\n\033[1m    <<<< ADMIN MENU >>>>\033[0m\n");
        printf("===========================\n");
        printf("1. View Applications\n");
        printf("2. Add Staff\n");
        printf("3. Delete Staff\n");
        printf("4. Add Bus Route\n");
        printf("5. Remove Bus Route\n");
        printf("6. View Complaints & Issues\n");
        printf("7. Update Fare Notice (Option 7 logic)\n");
        printf("8. Manage Emergency Contacts\n");
        printf("9. Delete User\n");
        printf("10. Show All Approved Users\n"); 
        printf("11. Search ID Validity\n"); 
        printf("0. Logout\n");
        printf("\n---------------------------\n");
        printf("Choice: ");
        scanf("%d", &option);
        getchar();

        if(option == 0) return;
        else if(option == 1) ViewNewApplicants();
        else if(option == 2) StuffSellection();
        else if(option == 3) deleteStuff();
        else if(option == 4) AddBusRoute();
        else if(option == 5) RemoveBusRoute();
        else if(option == 6) ViewReportsAdmin();
        else if(option == 7) ManageNotice(1);
        else if(option == 8) Emergency_Contact(1);
        else if(option == 9) deleteUseMenu();
        else if(option == 10) ShowAllUsers(); 
        else if(option == 11) SearchIDValidity();
        else printf("Invalid choice.\n");
    }
}

void Student_Menu(char currentID[]){
    int option;
    struct user *u = student;
    while(u && strcmp(u->id, currentID) != 0) u = u->next;

    while(1){
        printf("\n\033[1m    <<<< STUDENT MENU >>>>\033[0m\n");
        printf("===========================\n");
        printf("\n1. Your Route and Schedule\n");
        printf("2. Fare Info\n");
        printf("3. Complain Against Staff\n");
        printf("4. Update Profile\n"); 
        printf("5. Submit Bkash Payment (Option 5)\n");
        printf("6. Search Specific Route\n");
        printf("7. Check My Dedicated Assignment\n");
        printf("0. Logout\n");
        printf("\n---------------------------\n");
        printf("Enter Your Choice: ");
        scanf("%d", &option);
        getchar();

        if(option == 0) return;
        else if(option == 1) DisplayBusRoutes();
        else if(option == 2) Bus_Fare_Info(2);
        else if(option == 3) {
            char staffID[30];
            printf("\n--- Report a Staff Member ---\n");
            printf("Enter Staff ID you are reporting: ");
            scanf(" %[^\n]", staffID);
            addReport("Student Complaint", currentID, staffID);
        }
        else if(option == 4) UpdateProfile(student, currentID); 
        else if(option == 5) SubmitBkashPayment(u);
        else if(option == 6) Specific_Bus_Schedule(routeList);
        else if(option == 7) Check_My_Schedule(currentID);
        else printf("Invalid option!! Try again.\n");
    }
}

void Faculty_Menu(char currentID[]){
    int option;
    struct user *u = faculty;
    while(u && strcmp(u->id, currentID) != 0) u = u->next;

    while(1){
        printf("\n\033[1m    <<<< FACULTY MENU >>>>\033[0m\n");
        printf("===========================\n");
        printf("\n1. Your Route and Schedule\n");
        printf("2. Fare Info\n");
        printf("3. Complain or Feedback\n"); 
        printf("4. Update Profile\n"); 
        printf("5. Submit Bkash Payment (Option 5)\n");
        printf("6. Search Specific Route\n");
        printf("7. Check My Dedicated Assignment\n");
        printf("0. Logout\n");
        printf("\n---------------------------\n");
        printf("Enter Your Choice: ");
        scanf("%d", &option);
        getchar();

        if(option == 0) return;
        else if(option == 1) DisplayBusRoutes();
        else if(option == 2) Bus_Fare_Info(2);
        else if(option == 3) {
            printf("\n--- Faculty Feedback ---\n");
            addReport("Faculty Feedback", currentID, "Management");
        }
        else if(option == 4) UpdateProfile(faculty, currentID); 
        else if(option == 5) SubmitBkashPayment(u);
        else if(option == 6) Specific_Bus_Schedule(routeList);
        else if(option == 7) Check_My_Schedule(currentID);
        else printf("Invalid option!! Try again.\n");
    }
}

void Bus_Staff_Menu(char currentID[]){ 
    int option;
    while(1){
        printf("\n\033[1m    <<<< BUS STAFF MENU >>>>\033[0m\n");
        printf("===========================\n");
        printf("1. View Assigned Routes\n");
        printf("2. Complain Against Student\n"); 
        printf("3. Search ID Validity\n");
        printf("0. Logout\n");
        printf("\n---------------------------\n");
        printf("Enter Your Choice: ");
        scanf("%d", &option);
        getchar();

        if(option == 0) return;
        else if(option == 1) DisplayBusRoutes();
        else if(option == 2) { 
            char studentID[30];
            printf("Enter Student ID: ");
            scanf("%s", studentID);
            getchar();
            addReport("Staff Complaint", currentID, studentID);
        }
        else if(option == 3) SearchIDValidity();
        else printf("Invalid option!! Try again.\n");
    }
}

struct user* searchLogin(struct user* temp, char ID[30], char pass[30]){
    while(temp != NULL && strcmp(temp->id, ID) != 0){
        temp = temp->next;
    }

    if(temp == NULL){
        printf("The user is not found\n");
        return NULL;
    }

    if(temp->approve == 0){
        printf("Your application is not approved yet\n");
        return NULL;
    }

    if(strcmp(temp->password, pass) == 0){
        return temp;
    }else{
        printf("Password is incorrect\n");
        return NULL;
    }
}

struct employ* searchStaffLogin(struct employ* temp, char ID[30], char pass[30]){
    while(temp != NULL && strcmp(temp->id, ID) != 0){
        temp = temp->next;
    }

    if(temp == NULL){
        printf("The staff is not found\n");
        return NULL;
    }

    if(strcmp(temp->password, pass) == 0){
        return temp;
    }else{
        printf("Password is incorrect\n");
        return NULL;
    }
}

void Student_Login(){
    int option;
    char ID[50];
    char pass[50];

    while(1){
        printf("\n\033[1m    <<<< STUDENT LOGIN >>>>\033[0m\n");
        printf("===========================\n");

        printf("\n\033[1m  Sign in to your account\033[0m\n");

        printf("\nStudent ID : ");
        scanf("%s", ID);
        getchar();

        printf("Password : ");
        scanf("%s", pass);
        getchar();

        struct user *found = searchLogin(student, ID, pass);

        if(found){
            Student_Menu(found->id);
            return;
        }

        printf("\n1. Forget Password\n");
        printf("0. Back\n");
        printf("\n---------------------------\n");

        printf("Enter Your Choice: ");
        scanf("%d", &option);
        getchar();

        if(option == 0){
            return;
        } 
        else if(option == 1){
            printf("Contact with transport office.\n");
        }
        else{
            printf("Invalid Choice!! Try Again.\n");
        }
    }
}

void Faculty_Login(){
    int option;
    char ID[50], pass[50];

    while(1){
        printf("\n\033[1m    <<<< FACULTY LOGIN >>>>\033[0m\n");
        printf("===========================\n");

        printf("\n\033[1m  Sign in to your account\033[0m\n");
        printf("\nFaculty ID : ");
        scanf("%s", ID);
        getchar();

        printf("Password: ");
        scanf("%s", pass);
        getchar();

        struct user *found = searchLogin(faculty, ID, pass);

        if(found){
            Faculty_Menu(found->id);
            return;
        }
        else{
            printf("\n1. Forget Password\n");
            printf("0. Back\n");
            printf("\n---------------------------\n");

            printf("Enter Your Choice: ");
            scanf("%d", &option);
            getchar();

            if(option == 0){
                return;
            } 
            else if(option == 1){
                printf("Contact with transport office.\n");
            }
            else{
                printf("Invalid Choice!! Try Again.\n");
            }
        }
    }
}

void Admin_Login(){
    int option;
    char ID[50], pass[50];

    while(1){
        printf("\n\033[1m    <<<< ADMIN LOGIN >>>>\033[0m\n");
        printf("===========================\n");

        printf("\n\033[1m  Sign in to your account\033[0m\n");
        printf("\nAdmin ID : ");
        scanf("%s", ID);
        getchar();

        printf("Password: ");
        scanf("%s", pass);
        getchar();

        if(strcmp(ID, "admin.diu") == 0 && strcmp(pass, "admin123") == 0){
            Admin_Menu();
            return;
        }else{
            printf("\n1. Forget Password\n");
            printf("0. Back\n");
            printf("\n---------------------------\n");

            printf("Enter Your Choice: ");
            scanf("%d", &option);
            getchar();

            if(option == 0){
                return;
            } 
            else if(option == 1){
                printf("Contact with transport office.\n");
            }
            else{
                printf("Invalid Choice!! Try Again.\n");
            }
        }
    }
}

void Bus_Stuff_Login(){
    int option;
    char ID[50], pass[50];

    while(1){
        printf("\n\033[1m    <<<< BUS STAFF LOGIN >>>>\033[0m\n");
        printf("===========================\n");

        printf("\n\033[1m  Sign in to your account\033[0m\n");
        printf("\nStuff ID: ");
        scanf("%s", ID);
        getchar();

        printf("Password: ");
        scanf("%s", pass);
        getchar();

        struct employ* found = searchStaffLogin(stuff, ID, pass);

        if(found){
            Bus_Staff_Menu(found->id); 
            return;
        }

        printf("\n1. Forget Password\n");
        printf("0. Back\n");
        printf("\n---------------------------\n");

        printf("Enter Your Choice: ");
        scanf("%d", &option);
        getchar();

        if(option == 0){
            return;
        } 
        else if(option == 1){
            printf("Contact with transport office.\n");
        }
        else{
            printf("Invalid Choice!! Try Again.\n");
        }
    }
}

void applyUser(){
    int option;
    while(1){
        printf("\033[1m     FACULTY OR STUDENT     \033[0m\n");
        printf("===========================\n\n");

        printf("1. Student\n");
        printf("2. Faculty\n");
        printf("0. Exit\n");
        printf("\n---------------------------\n");

        printf("Enter Your Choice: ");
        scanf("%d", &option);
        getchar();

        if(option == 1){
            student = insertUser(student, 1);
            return;
        }else if(option == 2){
            faculty = insertUser(faculty, 2);
            return;
        }else if(option == 0){
            return;
        }else{
            printf("Invalid option!! Try again.\n");
        }
    }
}

void Main_Menu(){
    int option;
    while(1){
        printf("\n\033[1m    <<<< DIU TRANSPORT >>>>\033[0m\n");
        printf("===============================\n");
        printf("1. Apply for Membership\n");
        printf("2. Student Login\n");
        printf("3. Faculty Login\n");
        printf("4. Bus Staff Login\n");
        printf("5. Admin Login\n");
        printf("6. Emergency Contacts\n");
        printf("7. Report Issue\n");
        printf("8. View Current Fare/Transport Notice\n");
        printf("0. Exit\n");
        printf("\n---------------------------\n");
        printf("Choice: ");
        scanf("%d", &option);
        getchar();

        if(option == 0) break;
        else if(option == 1) applyUser();
        else if(option == 2) Student_Login();
        else if(option == 3) Faculty_Login();
        else if(option == 4) Bus_Stuff_Login();
        else if(option == 5) Admin_Login();
        else if(option == 6) Emergency_Contact(2);
        else if(option == 7)  addReport("General Issue", "Guest", "N/A");
        else if(option == 8) ManageNotice(0);
        else printf("Invalid option!\n");
    }
}

int main(){
    loadData();
    Main_Menu();
    saveData();
    return 0;
}
