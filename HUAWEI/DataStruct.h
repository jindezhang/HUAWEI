//数据结构学习
/*
//哈希表，散列表。
//解决冲突，链地址法
//使用模板；
//[1] 模板哈希表
//【2】2018年12月6日10点00分
        支持动态扩容，扩容之后，进行数据迁移。【未实现】
            */

#include <vector>
#include <cstring>
#include <functional>
typedef size_t UINT;

template <typename K, typename T> 
struct Node{
    K key;
    T value;
    Node<K, T> *next;
};

template <typename K, typename T>
class HashTable{
public:
    explicit HashTable(UINT size);
    UINT hash(K key );//stl自带的hash算法。
    Node<K, T>* lookup( K key );
    bool install( K key, T value );
    bool del( K key );
    const T get( K key );
    void display(void (*show)(T) );

private:
    const UINT m_size;
    std::vector<Node<K,T> *> m_node;
};

template<typename K, typename T>
inline HashTable<K, T>::HashTable( UINT size ):m_size(size)
{
    for ( int i = 0; i < size; ++i )
    {
        Node<K, T>* node = nullptr;
        m_node.push_back( node );
    }
}

template<typename K, typename T>
inline UINT HashTable<K, T>::hash( K key )
{
    std::hash<K> hash_fn;
    size_t hash = hash_fn( key );
    
    return hash%m_size;
}

template<typename K, typename T>
inline Node<K, T>* HashTable<K, T>::lookup( K key )
{
    Node<K, T> *np;
    UINT index;
    index = hash( key );
    for ( np = m_node[ index ]; np; np = np->next )
    {
        //strcmp if == return 0 #include <cstring>
        if ( key == np->key )
            return np;
        else
            std::cout << "conflict\n";
    }
    return nullptr;
}

template<typename K, typename T>
inline bool HashTable<K, T>::install( K key, T value )
{
     Node<K, T> *np;
    UINT index;
    if (!(np = lookup(key))){
        np = new Node<K, T>;
        if ( !np )
            return false;
        index = hash( key );
        np->key = key;
        //插入到首位
        np->next = m_node[ index ];
        m_node[ index ] = np;
    }
    np->value = value;
    return true;
}

template<typename K, typename T>
inline bool HashTable<K, T>::del( K key )
{
    Node<K, T> *np;
    Node<K, T> *tmp = nullptr;
    UINT index = hash( key );

    for ( np = m_node[ index ]; np; tmp = np, np = np->next )
    {
        //strcmp if == return 0 #include <cstring>
        if ( key == np->key )
        {
            //first time
            if (!tmp){
                m_node[ index ] = np->next;
                delete np;
                break;
            }
            else
            {
                tmp->next = np->next;
                np->next = nullptr;
                delete np;
                break;
            }
        }
        
    }

    return true;
}

template<typename K, typename T>
inline const T HashTable<K, T>::get( K key )
{
    Node<K, T> *np;
    
    if((np = lookup( key ))){
        return np->value;
    }
    
    return -1;
}

template<typename K, typename T>
inline void HashTable<K, T>::display( void( *show )( T ) )
{
    std::for_each( m_node.begin(), m_node.end(), [ show ]( Node<K, T>* node ){
        
        if ( node )
        {
            do
            {
                show( node->value );
            } while ( (node = node->next) );
        }
        else
        {
            std::cout << "NULL\t";
        }
        std::cout <<"--->" << std::endl;
    } );
    
    std::cout << std::endl;
}
