/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Use a min heap to store the muminum k numbers, each time
        // we insert the minimun number of the k numbers into result list
        // and update the heap
        // Step 1 : create a output list
        // Step 2 : create a min heap of size k and insert the first element of all the k lists into the heap
        // Step 3 : 1) find the smallest val in heap(at root) and store it in output list
        //          2) replace the root node with the node after the smallest val which is extracted. If the list
        //              does not have any more node replace the root node with INT_MAX. Heapify the heap
        
        // Step 1
        ListNode ret(-1);
        ListNode *now = &ret;
        // Step 2:
        int k=0;
        for(auto ptr =  lists.begin(); ptr != lists.end(); )
            if(*ptr != NULL){
                k++;
                ptr++;
            }else
                lists.erase(ptr);
                
        MinNode * node= new MinNode[k];
        for(int i=0; i < k; i++)
            node[i].element = lists[i];
        MinHeap heap(node, k);
        // Step 3:

        while(true){
            if(heap.heap_size < 1)
                break;
                
            MinNode root = heap.getMin();
            ListNode * cur = root.element;
            now->next = cur; now = now->next;
        
            if(cur->next != NULL){
                root.element = cur->next;
                heap.replaceMin(root);
            }else{
                heap.extracted();
            }

        }
        
        return ret.next;
    }
    
private:
    // utility function to use min heap
    
    // A min heap Node
    struct MinNode{
        ListNode * element;
    };
    // 
    class MinHeap{
    private:
        MinNode * heap;
    public:
        int heap_size;
        // Constructor: creates a min heap of given size
        MinHeap (MinNode h[], int l)
        {
            heap_size = l;
            heap = h;
            int i = (heap_size/2)-1;
            while(i >= 0)
                MinHeapify(i--);
        }
    
        // to heapify a subtree with root at given index
        void MinHeapify(int idx)
        {    
            int l = left(idx);
            int r = right(idx);
            int smallest = idx;
            if (l < heap_size && heap[l].element->val < heap[idx].element->val)
                smallest = l;
            if (r < heap_size && heap[r].element->val < heap[smallest].element->val)
                smallest = r;
            if (smallest != idx)
            {
                MinNode  temp = heap[idx];
                heap[idx] = heap[smallest];
                heap[smallest] = temp;
                MinHeapify(smallest);
            }
        }
     
        // to get index of left child of node at index i
        int left(int i) { return (2*i + 1); }
     
        // to get index of right child of node at index i
        int right(int i) { return (2*i + 2); }
     
        // to get the root
        MinNode getMin() { return heap[0]; }
     
        // to replace root with new node x and heapify() new root
        void replaceMin(MinNode x) { heap[0] = x;  MinHeapify(0); }  
        
        // to pop up root element
        void extracted(){
            heap[0] = heap[heap_size-1];
            heap_size--;
            MinHeapify(0);
        }
        
    };
    
};
