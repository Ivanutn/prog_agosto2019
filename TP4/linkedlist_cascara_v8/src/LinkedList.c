#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;// siempre es aconsejable asignar NULL a un puntero.
    this = (LinkedList*)malloc(sizeof(LinkedList));
    if(this!=NULL) //valido para poder settear los campos.
    {
        this->size=0;
        this->pFirstNode=NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        returnAux=this->size;//size
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* retornoNodo=NULL;

    if(this!=NULL && nodeIndex>=0 && nodeIndex<ll_len(this))
    {
        retornoNodo=this->pFirstNode;
        for(int i=0; i<nodeIndex; i++)
        {
                retornoNodo=retornoNodo->pNextNode;
        }

    }

    return retornoNodo;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{

    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* nuevoNodo=NULL; //nodo que contiene el pElement y que se va a insertar en alguna posicion.
    Node* aux=NULL;


    if(this!=NULL && nodeIndex>=0 && nodeIndex<=ll_len(this))
    {
        nuevoNodo=(Node*)malloc(sizeof(Node));
        if(nuevoNodo!=NULL)
        {
            nuevoNodo->pElement=pElement;
            nuevoNodo->pNextNode=NULL;
        }

        if(nodeIndex==0 && ll_len(this)==0) //LL solamente tiene al LL
        {
            this->pFirstNode=nuevoNodo;
        }
        else if(nodeIndex==0 &&ll_len(this)>0) //signicica que elije la posicion cero pero el LL tiene datos
        {
            aux=getNode(this,nodeIndex);
            nuevoNodo->pNextNode=aux;
            this->pFirstNode=nuevoNodo;

        }
        else if(nodeIndex>0 && ll_len(this)>0)
        {
            aux=getNode(this,nodeIndex-1);
            nuevoNodo->pNextNode=aux->pNextNode;
            aux->pNextNode=nuevoNodo;
        }
        else if(nodeIndex==ll_len(this))
        {
            aux=getNode(this,nodeIndex-1);
            aux->pNextNode=nuevoNodo;
            nuevoNodo->pNextNode=NULL;
        }

        this->size++;
        returnAux=0;
    }


    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        if(ll_len(this)==0)//si el unico elemento es el LL, lo agrego en el primer nodo.
        {
            addNode(this,0,pElement);
        }
        else
        {
            addNode(this,ll_len(this),pElement);
        }


         returnAux=0;
    }


    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* aux=NULL;
    aux=(Node*)malloc(sizeof(Node));
    if(aux!=NULL)
    {
        aux->pElement=NULL;
        aux->pNextNode=NULL;
    }
    if(this!=NULL && index>=0 && index < ll_len(this))
    {
        if(index==0)
        {
            aux=getNode(this,index);
            returnAux=aux->pElement;
        }
        else if(index>0 && index< ll_len(this))
        {
           aux=getNode(this,index);
           returnAux=aux->pElement;
        }


    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* setNode=NULL;

    if(this!=NULL && index>=0 && index<ll_len(this))
    {
        if(index==0)
        {
            addNode(this,index,pElement);
        }
        if(index==ll_len(this))
        {
            addNode(this,index,pElement);
        }
        else if(index>0 && index<ll_len(this))
        {
            setNode=getNode(this,index);
            setNode->pElement=pElement;
        }

        returnAux=0;

    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* deleteNode=NULL;
    Node* aux=NULL;
    if(this!=NULL && index>=0 && index<ll_len(this))
    {
        if(index==0)
        {
            this->pFirstNode=NULL;
            free(this);
        }

        else if(index>0)
        {
            deleteNode=getNode(this,index);
            aux=getNode(this,index-1);
            aux->pNextNode=deleteNode->pNextNode;
            free(deleteNode);
        }
        else if(index==ll_len(this)-1)
        {
            deleteNode=getNode(this,index);
            aux=getNode(this,index-1);
            aux->pNextNode=NULL;
            free(deleteNode);
        }

        this->size--;
        returnAux=0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        if(ll_len(this)==0)
        {
           ll_remove(this,0);

        }
        for(int i=0; i<ll_len(this); i++)
        {
            ll_remove(this,i);
        }

       returnAux=0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        if(ll_len(this)==0)
        {
            free(this);
            returnAux=1;
        }
        else if(ll_len(this)>0)
        {
            ll_clear(this);
            free(this);
            returnAux=0;
        }
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* aux=NULL;
    Node* contenedor=NULL;
    aux=(Node*)malloc(sizeof(Node));
    if(aux!=NULL)
    {
        aux->pElement=pElement;
        aux->pNextNode=NULL;
    }
    if(this!=NULL)
    {
        for(int i=0;i<ll_len(this);i++)
        {
            contenedor=getNode(this,i);
            if(aux->pElement==contenedor->pElement)
            {
                returnAux=i;
                break;
            }
        }

    }
    free(aux);
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        if(ll_len(this)==0)
        {
            returnAux=1;
        }
        else
        {
            returnAux=0;
        }

    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL && index >=0 && index<=ll_len(this))
    {

        if(index==0)
        {
           // ll_add(this,pElement);
           addNode(this,index,pElement);
        }

        else if(index==ll_len(this))
        {
            //ll_add(this,pElement);
            addNode(this,index,pElement);
        }
        else if(index>0&&ll_len(this)>0)
        {
           // ll_add(this,pElement);
            addNode(this,index,pElement);
        }


        returnAux=0;

    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    if(this!=NULL && index>=0 && index<ll_len(this))
    {
        returnAux=ll_get(this,index);
        ll_remove(this,index);
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        if(ll_indexOf(this,pElement)!=-1)
        {
            returnAux=1;
        }
        else
        {
            returnAux=0;
        }

    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int flag=0;
    if(this!=NULL && this2!=NULL)
    {
        for(int i=0;i<ll_len(this);i++)
        {
            flag=0;
             if(ll_contains(this2,ll_get(this,i)))
            {
                flag=1;
            }
            if(flag==0)
            {
                break;
            }

        }
        if(flag==1)
        {
            returnAux=1;
        }
        else
        {
            returnAux=0;
        }


    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    if(this!=NULL && from>=0 && from <=ll_len(this) && to>=from && to<=ll_len(this))
    {
        cloneArray=ll_newLinkedList();
        if(cloneArray!=NULL)
        {
            for(int i=from; i<to; i++)
            {

                ll_add(cloneArray,ll_get(this,i));
            }
        }

    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;

    return returnAux;

}

