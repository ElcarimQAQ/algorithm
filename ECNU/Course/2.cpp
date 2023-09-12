#include <bits/stdc++.h>
using namespace std;

vector<int> arr1, arr2;
struct Node {
    int value;
    Node* leftChild;
    Node* rightChild;
    Node(int val) {
        value = val;
        leftChild = nullptr;
        rightChild = nullptr;
    }
};

//  小根堆
Node* mergeHeaps(Node* heap1, Node* heap2) {
    if (heap1 == nullptr) {
        return heap2;
    }
    if (heap2 == nullptr) {
        return heap1;
    }
    
    Node* mergedHeap;
    
    if (heap1->value < heap2->value) {
        mergedHeap = heap1;
        mergedHeap->rightChild = mergeHeaps(heap1->rightChild, heap2);
    } else {
        mergedHeap = heap2;
        mergedHeap->rightChild = mergeHeaps(heap1, heap2->rightChild);
    }
    
    // 交换左右子指针以维护堆
    if (mergedHeap->rightChild != nullptr && mergedHeap->leftChild != nullptr && mergedHeap->leftChild->value > mergedHeap->rightChild->value) {
        Node* temp = mergedHeap->leftChild;
        mergedHeap->leftChild = mergedHeap->rightChild;
        mergedHeap->rightChild = temp;
    }
    
    return mergedHeap;
}


// 创建堆
Node* buildHeap(const vector<int>& arr, int n) {
    if (n == 0)
        return nullptr;

    Node* root = new Node(arr[0]);

    queue<Node*> nodeQueue;
    nodeQueue.push(root);

    int i = 1;

    // 层序遍历构建堆
    while (!nodeQueue.empty() && i < n) {
        Node* curr = nodeQueue.front();
        nodeQueue.pop();

        // 创建左子节点
        if (i < n) {
            curr->leftChild = new Node(arr[i]);
            nodeQueue.push(curr->leftChild);
            i++;
        }

        // 创建右子节点
        if (i < n) {
            curr->rightChild = new Node(arr[i]);
            nodeQueue.push(curr->rightChild);
            i++;
        }
    }

    return root;
}


// 打印堆, 前序遍历
void printHeap(Node* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->value <<' ';
    if (root->leftChild != nullptr)
        cout<<root->leftChild->value<<' ';
    else  
        cout<<"null"<<' ';
    if (root->rightChild != nullptr)
        cout<<root->rightChild->value<<endl;
    else  
        cout<<"null"<<endl;
    if (root->leftChild != nullptr){
        cout<< 'L'<< endl;
        printHeap(root->leftChild);
    }if (root->rightChild != nullptr){
        cout<< 'R'<< endl;
        printHeap(root->rightChild);
    }
}


int main() {
    int n,m, num;
    cin>>n>>m;
    for(int i = 0;i < n; i++) {
        cin>>num;
        arr1.push_back(num);
    }
    for(int i =0;i < m; i++){
        cin>>num;
        arr2.push_back(num);
    }

    // 构建堆1和堆2
    Node* heap1 = buildHeap(arr1, n);

    Node* heap2 = buildHeap(arr2, m);

    // 合并堆1和堆2
    Node* mergedHeap = mergeHeaps(heap1, heap2);

    // 打印合并后的堆
    printHeap(mergedHeap);

    return 0;
}