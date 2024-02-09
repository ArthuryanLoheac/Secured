# secured
Compilation avec :  
> make

Bibliothèque de fonctions :  
Fonction de hash :  
>int hash (char * key, int len);  

Création de la table de hachage :  
>hashtable_t * new_hashtable (int (* hash ) ( char * , int) , int len ); 

Suppression de la table de hachage : 
>void delete_hashtable ( hashtable_t * ht );  

Ajouter un élément à la table :  
>int ht_insert ( hashtable_t * ht , char * key , char * value );  

Supprimer un élément de la table :  
>int ht_delete ( hashtable_t * ht , char * key );  

Chercher un élément dans la table :  
>char * ht_search ( hashtable_t * ht , char * key );  

Affichage de la table :  
>void ht_dump ( hashtable_t * ht );  


