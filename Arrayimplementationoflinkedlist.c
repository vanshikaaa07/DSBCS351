#include <stdio.h>

#define MAX 10

struct Node {
    int data;
    int next;
};

int main() {
    struct Node list[MAX];
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    
    for (i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &list[i].data);

        if (i == n - 1)
            list[i].next = -1;  
        else
            list[i].next = i + 1;
    }

  
    printf("\nLinked List: ");

    i = 0;  

    while (i != -1) {
        printf("%d -> ", list[i].data);
        i = list[i].next;
    }

    printf("NULL\n");

    return 0;
}
