node_pila* copia_node_pila_it(node_pila* m){
  if(m == NULL) return NULL;
  node_pila* n;
  node_pila* n1;
  n = n1 = new node_pila;
  n1->info = m->info;
  m = m->seguent;	
  
  while(m != NULL){
  	
  	n1->seguent = new node_pila;
  	n1 = n1 ->seguent;
  	n1->info = m->info;
  	m = m->seguent;
  	
  }
  n1->seguent = NULL;
  return n;
} 
/* Pre: cert */
/* Post: si m és NULL, el resultat és NULL; en cas contrari, el
resultat apunta al primer node d'una cadena de nodes que són
còpia de de la cadena que té el node apuntat per m com a primer */



Pila& operator=(const Pila& original){
  this->altura = original.altura;
  this->primer_node = copia_node_pila_it(original.primer_node);
  return *this;
}
/* Pre: cert */
/* Post: El p.i. passa a ser una còpia d'original i qualsevol
contingut anterior del p.i. ha estat esborrat (excepte si el
p.i. i original ja eren el mateix objecte) */
  
