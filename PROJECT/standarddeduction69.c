#include <stdio.h>

void deduction() {
    float salary, tax = 0, final_salary, surcharge = 0, total_tax;
    float cess_rate = 0.04;

    printf("Enter the salary: ");
    scanf("%f", &salary);

    if (salary < 0) {
        printf("Invalid input\n");
        return;
    }

    if (salary <= 300000) {
        tax = 0;
    } else if (salary <= 600000) {
        tax = (salary - 300000) * 0.05;
    } else if (salary <= 900000) {
        tax = (300000 * 0.05) + (salary - 600000) * 0.10;
    } else if (salary <= 1200000) {
        tax = (300000 * 0.05) + (300000 * 0.10) + (salary - 900000) * 0.15;
    } else if (salary <= 1500000) {
        tax = (300000 * 0.05) + (300000 * 0.10) + (300000 * 0.15) + (salary - 1200000) * 0.20;
    } else {
        tax = (300000 * 0.05) + (300000 * 0.10) + (300000 * 0.15) + (300000 * 0.20) + (salary - 1500000) * 0.30;

    
        if (salary > 5000000 && salary <= 10000000) {
            surcharge = 0.10 * tax;
        } else if (salary > 10000000 && salary <= 20000000) {
            surcharge = 0.20 * tax;
        } 
    }

    float cess = (tax + surcharge) * cess_rate;

    total_tax = tax + surcharge + cess;
    final_salary = salary - total_tax;

    printf("Salary before tax: %.2f\n", salary);
    printf("Salary after deduction: %.2f\n", final_salary);
    printf("Total tax: %.2f\n", total_tax);
}


