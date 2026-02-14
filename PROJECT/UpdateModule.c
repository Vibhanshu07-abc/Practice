void updateEmployee() {
    int update, found = 0;
    printf("Enter Employee user name  to update: ");
    scanf("%d", &update);

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            found = 1;
            printf("Enter new name: ");
            scanf("%s", employees[i].name);
            printf("Enter new salary: ");
            scanf("%f", &employees[i].salary);
            printf("Enter new deduction: ");
            scanf("%f", &employees[i].deduction);
            printf("Employee updated successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Employee ID not found.\n");
    } else {
        saveToFile();
    }
}
