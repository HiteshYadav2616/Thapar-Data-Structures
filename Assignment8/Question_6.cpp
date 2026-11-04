#include<iostream>
using namespace std;

class PriorityQueue {
    int arr[100];
    int n;

    public:
        PriorityQueue() : n(0) {}

        void insert(int data) {
            if(n==100) {
                cout << "Priority Queue is full" << endl;
                return;
            }

            int i = n;
            arr[n] = data;
            n++;

            while(i>0 && arr[(i-1)/2] < arr[i]) {
                swap(arr[i], arr[(i-1)/2]);
                i = (i-1)/2;
            }
        }

        void heapify(int i) {
            int largest = i;
            int left = 2*i+1;
            int right = 2*i+2;

            if(left < n && arr[left]>arr[largest]) largest = left;
            if(right < n && arr[right]>arr[largest]) largest = right;

            if(largest != i) {
                swap(arr[i], arr[largest]);
                heapify(largest);
            }
        }

        void deleteMax() {
            if(n==0) {
                cout << "Priority queue is empty" << endl;
                return;
            }
            cout << "Deleted: " << arr[0] << endl;

            arr[0] = arr[n-1];
            n--;

            heapify(0);
        }

        void peek() {
            if (n==0)
                cout << "Priority Queue is empty\n";
            else
                cout << "Highest priority: " << arr[0] << endl;
        }

        void display() {
            if (n==0) {
                cout << "Priority Queue is empty\n";
                return;
            }

            cout << "Elements: ";

            for (int i = 0; i < n; i++)
                cout << arr[i] << " ";

            cout << endl;
        }

};

int main()
{
    PriorityQueue pq;

    pq.insert(40);
    pq.insert(20);
    pq.insert(60);
    pq.insert(10);
    pq.insert(50);

    pq.display();

    pq.peek();

    pq.deleteMax();

    pq.display();

    return 0;
}