#include <stdio.h>

int main() {
    int n = 0, arr[100], choice, value, pos, sum, temp, found;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Nhap so phan tu va gia tri cho mang\n");
        printf("2. In ra gia tri cac phan tu trong mang\n");
        printf("3. Tim gia tri nho nhat va lon nhat trong mang\n");
        printf("4. In ra tong cua tat ca cac phan tu\n");
        printf("5. Them mot phan tu vao cuoi mang\n");
        printf("6. Xoa phan tu tai mot vi tri cu the\n");
        printf("7. Sap xep mang theo thu tu giam dan\n");
        printf("8. Tim kiem phan tu trong mang\n");
        printf("9. In ra toan bo so nguyen to trong mang\n");
        printf("10. Sap xep mang theo thu tu tang dan (Selection sort)\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Nhap so phan tu cua mang (toi da 100): ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Nhap gia tri cho arr[%d]: ", i);
                    scanf("%d", &arr[i]);
                }
                break;
            case 2:
                printf("In ra gia tri cac phan tu trong mang:\n");
                for (int i = 0; i < n; i++) {
                    printf("arr[%d] = %d", i, arr[i]);
                    if (i < n - 1) printf(", ");
                }
                printf("\n");
                break;
            case 3:
                if (n > 0) {
                    int min = arr[0], max = arr[0];
                    for (int i = 1; i < n; i++) {
                        if (arr[i] < min) min = arr[i];
                        if (arr[i] > max) max = arr[i];
                    }
                    printf("Gia tri nho nhat: %d\n", min);
                    printf("Gia tri lon nhat: %d\n", max);
                } else {
                    printf("Mang rong!\n");
                }
                break;
            case 4:
                sum = 0;
                for (int i = 0; i < n; i++) {
                    sum += arr[i];
                }
                printf("Tong cac phan tu trong mang: %d\n", sum);
                break;
            case 5:
                if (n < 100) {
                    printf("Nhap gia tri can them vào cuoi mang: ");
                    scanf("%d", &value);
                    arr[n++] = value;
                } else {
                    printf("Mang da day!\n");
                }
                break;
            case 6:
                printf("Nhap vi tri can xoa (0 den %d ): ", n - 1);
                scanf("%d", &pos);
                if (pos >= 0 && pos < n) {
                    for (int i = pos; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    n--;
                } else {
                    printf("Vi tri khong hop le!\n");
                }
                break;
            case 7:
                for (int i = 0; i < n - 1; i++) {
                    for (int j = 0; j < n - 1 - i; j++) {
                    if (arr[j] < arr[j + 1]) {
                            temp = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = temp;
                        }
                    }
                }
                printf("Mang da duoc sap xep giam dan.\n");
                break;
            case 8:
                printf("Nhap phan tu can tim: ");
                scanf("%d", &value);
                found = 0;
                for (int i = 0; i < n; i++) {
                    if (arr[i] == value) {
                        printf("Phan tu %d ton tai o vi tri arr[%d].\n", value, i);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Phan tu %d khong ton tai trong mang.\n", value);
                }
                break;

            case 0:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
        }
    } while (choice != 0);
    return 0;
}	
