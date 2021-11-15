/**        
 * @file  Node.h
 * @description Bu program bir text dosyasında belli düzene göre yazılmış satırları okuyarak işlemler yapmaktadır.
 * @course  1-A 
 * @assignment  1 
 * @date  06/11/2021  
 * @author  Ali Tayyip Uzunoglan(ali.uzunoglan@ogr.sakarya.edu.tr)
 **/
#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

class Node // Düğüm sınıfı oluşturuluyor.
{
public:
    Node *next;
    Node *prev;
    string kelime;
};
#endif