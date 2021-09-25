template <class T>
SLinkedList<T>::Iterator::Iterator(SLinkedList<T>* pList, bool begin)
{
    /*
        Constructor of iterator
        * Set pList to pList
        * begin = true: 
        * * Set current (index = 0) to pList's head if pList is not NULL
        * * Otherwise set to NULL (index = -1)
        * begin = false: 
        * * Always set current to NULL
        * * Set index to pList's size if pList is not NULL, otherwise 0
    */
    this->pList=pList;
    if (begin){
        if (this->pList !=NULL)
            {
            current=pList->head;
            index=0;
            }
        else 
            {
            current=NULL;
            index=-1;
            }
    }
    else{
        current=NULL;
        if (this->pList !=NULL)
            index = pList->size();
        else
            index=0;
    }
}

template <class T>
typename SLinkedList<T>::Iterator& SLinkedList<T>::Iterator::operator=(const Iterator& iterator)
{
    /*
        Assignment operator
        * Set this current, index, pList to iterator corresponding elements.
    */
     this->pList= iterator.pList;
     this->current=iterator.current;
     this->index=iterator.index;
     return (*this);
}

template <class T>
void SLinkedList<T>::Iterator::remove()
{
    /*
        Remove a node which is pointed by current
        * After remove current points to the previous node of this position (or node with index - 1)
        * If remove at front, current points to previous "node" of head (current = NULL, index = -1)
        * Exception: throw std::out_of_range("Segmentation fault!") if remove when current is NULL
    */
    if (current==NULL)
        throw std::out_of_range("Segmentation fault!");
    pList->removeAt(index);
    index--;
    if (index==-1){
        current=NULL;
    }
    else{
        Node *temp=pList->head;
        int temp2=index;
        while (temp2!=0)
        {
            temp=temp->next;
            temp2--;
        }
        current=temp;
    }
}

template <class T>
void SLinkedList<T>::Iterator::set(const T& e)
{
    /*
        Set the new value for current node
        * Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
    */
    if (current==NULL)
        throw std::out_of_range("Segmentation fault!");
    current->data= e;
    }

template <class T>
T& SLinkedList<T>::Iterator::operator*()
{
    /*
        Get data stored in current node
        * Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
    */
    if (current==NULL)
        throw std::out_of_range("Segmentation fault!");
    return current->data;
}

template <class T>
bool SLinkedList<T>::Iterator::operator!=(const Iterator& iterator)
{
    /*
        Operator not equals
        * Returns true if two iterators points the same node and index
    */
    return (this->current == iterator.current) && (this->index == iterator.index);
}
// Prefix ++ overload
template <class T>
typename SLinkedList<T>::Iterator& SLinkedList<T>::Iterator::operator++()
{
    /*
        Prefix ++ overload
        * Set current to the next node
        * If iterator corresponds to the previous "node" of head, set it to head
        * Exception: throw std::out_of_range("Segmentation fault!") if iterator corresponds to the end
    */
    if (current==pList->tail)
        throw std::out_of_range("Segmentation fault!");
    if (current==NULL&& index==-1){
        current=pList->head;
        index=0;
    }
    else{
        current=current->next;
        index++;
    }
    return (*this);
}
// Postfix ++ overload
template <class T>
typename SLinkedList<T>::Iterator SLinkedList<T>::Iterator::operator++(int)
{
    /*
        Postfix ++ overload
        * Set current to the next node
        * If iterator corresponds to the previous "node" of head, set it to head
        * Exception: throw std::out_of_range("Segmentation fault!") if iterator corresponds to the end
    */
        
    if (current==pList->tail)
        throw std::out_of_range("Segmentation fault!");
    Iterator *temp = new Iterator();
    temp->pList=this->pList;
    temp->current=this->current;
    temp->index = this->index;
    if (current==NULL && index==-1){
        current=pList->head;
        index=0;
        return *temp;
    }
    else{
        current=current->next;
        index++;
    }
    return *temp;
}
