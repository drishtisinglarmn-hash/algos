#include <iostream>
using namespace std;
void InsertHeap(int Tree[], int &N, int Item)
{
    // Add new node
    N = N + 1;
    int PTR = N;

    
    while (PTR > 1)
    {
        int Par = PTR / 2; 

        if (Item >= Tree[Par])
        {
            Tree[PTR] = Item;
            return;
        }

        Tree[PTR] = Tree[Par];

        PTR = Par;
    }

    Tree[1] = Item;
}


int DeleteHeap(int Tree[], int &N)
{
    if (N == 0)
    {
        cout << "Heap is Empty!" << endl;
        return -1;
    }

    //  Remove root
    int ITEM = Tree[1];

    int LAST = Tree[N];
    N = N - 1;

    
    int PTR = 1;
    int LEFT = 2;
    int RIGHT = 3;

    // Loop while both children exist
    while (RIGHT <= N)
    {
        if (LAST <= Tree[LEFT] && LAST <= Tree[RIGHT])
        {
            Tree[PTR] = LAST;
            return ITEM;
        }

        if (Tree[RIGHT] >= Tree[LEFT])
        {
            Tree[PTR] = Tree[LEFT];
            PTR = LEFT;
        }
        else
        {
            Tree[PTR] = Tree[RIGHT];
            PTR = RIGHT;
        }

        LEFT = 2 * PTR;
        RIGHT = LEFT + 1;
    }

    //LAST has only left child
    if (LEFT == N && LAST > Tree[LEFT])
        PTR = LEFT;

    Tree[PTR] = LAST;

    // Return deleted root
    return ITEM;
}

int main()
{
    int Tree[100];
    int N = 0;

    //Insert
    InsertHeap(Tree, N, 50);
    InsertHeap(Tree, N, 30);
    InsertHeap(Tree, N, 40);
    InsertHeap(Tree, N, 10);
    InsertHeap(Tree, N, 60);
    InsertHeap(Tree, N, 20);

    cout << "Heap after insertions: ";
    for (int i = 1; i <= N; i++)
        cout << Tree[i] << " ";
    cout << endl;

    // Delete
    int deleted = DeleteHeap(Tree, N);
    cout << "Deleted item: " << deleted << endl;

    cout << "Heap after deletion: ";
    for (int i = 1; i <= N; i++)
        cout << Tree[i] << " ";
    cout << endl;

    return 0;
}
