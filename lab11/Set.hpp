/*
*   @file   : Set.hpp
*   @author : Gehrig Keane
*   @date   : 2015.12.02
*   Purpose : Disjoint Set implementation
*/

#include <iostream>

Set::Set(int s)
{
    int* set = new int[s];
    for (int i = 0; i < s; i++)
        set[i] = i;

    size = s;
    node_arr = new sNode*[s];
    for (int i = 0; i < s; i++)
        node_arr[i] = new sNode(set[i]);
}

void Set::Union(int a, int b)
{
    sNode* node_a = nullptr;
    for (int i = 0; i < size; i++)
    {
        if (node_arr[i]->getValue() == a)
            node_a = node_arr[i];
    }

    sNode* node_b = nullptr;
    for (int i = 0; i < size; i++)
    {
        if (node_arr[i]->getValue() == b)
            node_b = node_arr[i];
    }
    
    node_a = find(node_a);
    node_b = find(node_b);

    if (node_a != nullptr && node_b != nullptr)
    {
        if (node_a->getRank() >= node_b->getRank())
            node_b->setParent(node_a);
        else
        {
            node_a->setParent(node_b);

            if (node_a->getRank() == node_b->getRank())
                node_b->setRank(node_b->getRank() + 1);
        }//else - a < b
    }//if - a and b valid
}//Union - union a and b

sNode* Set::find(sNode* node)
{
    if (node->getParent() == nullptr)
        return node;
    else
        return find(node->getParent());
}//find - node equivalent

int Set::find(int value)
{
    sNode* temp = nullptr;
    for (int i = 0; i < size; i++)
    {
        if (node_arr[i]->getValue() == value)
        {
            temp = node_arr[i];
            break;
        }//if -  
    }//for - 

    if (temp == nullptr)
        return -1;
    else
        return find(temp)->getValue();
}//find - int equivalent
