#include <stdio.h>

#include <math.h>

void square(double a, double b, double c) {
  
    double D = b * b - 4 * a * c;

    if (D > 0) {
      
        double x1 = (-b + sqrt(D)) / (2 * a);
      
        double x2 = (-b - sqrt(D)) / (2 * a);
      
        printf("x1 = %.2f, x2 = %.2f\n", x1, x2);
      
    } else if (D == 0) {
      
        double x = -b / (2 * a); 
      
        printf("x = %.2f\n", x);
      
    } else {
      
        printf("D < 0, the roots are complex, the square root of a negative number\n");
      
    }
  
}

void cube(double p, double q) {
  
    double A, B, Q;
  
    Q = pow(q / 2, 2) + pow(p / 3, 3);
  
    A = cbrt(-q / 2 + sqrt(Q));
  
    B = cbrt(-q / 2 - sqrt(Q));
  
    double x = A + B;
  
    printf("x = %.6f\n", x);
  
}

int main() {
  
    double p, q;
  
    int choice;

    while (1) {
      
        printf("Select the type of equation:\n");
      
        printf("1 - square\n");
      
        printf("2 - cube\n");
      
        printf("3 - exit\n");
      
        printf("Your choice: ");
      
        scanf("%d", &choice);

        if (choice == 1) {
          
            double a, b, c;
          
            printf("Enter coefficients a, b, c: ");
          
            scanf("%lf %lf %lf", &a, &b, &c);
          
            square(a, b, c); 
          
        } else if (choice == 2) {
          
            printf("Enter coefficients p, q: ");
          
            scanf("%lf %lf", &p, &q);
          
            cube(p, q);
          
        } else if (choice == 3) {
          
            printf("Exit\n");
          
            break;
          
        } else {
          
            printf("Invalid choice!\n");
          
        }
      
    }

    return 0;
}
