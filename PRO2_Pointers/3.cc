node_llista* copia_node_llista_it (node_llista* m, node_llista* oact, node_llista* &u, node_llista* &a){
	if(m == NULL){
		u = a = NULL;
		return m;
	}else{
		a = NULL;
		node_llista* primer_node_copia = NULL;
		bool first = true;
		node_llista* aux = NULL;
		
		while(m!=NULL){
			node_llista* nou_node;
			nou_node = new node_llista;
			
			nou_node->info = m->info;
			
			if(aux != NULL) aux->seg = nou_node;
			nou_node->ant = aux;
			if(first){
				first = false;
				primer_node_copia = nou_node;
			}
			
			if(oact == m){
				a = nou_node;
			}
			aux = nou_node;
			m = m->seg;
		}
		u = aux;
		return primer_node_copia;
		
	}

}
/* Pre: cert */
/* Post: si m �s NULL, el resultat, u i a s�n NULL; en cas
       contrari, el resultat apunta al primer node d'una cadena de
       nodes que s�n c�pia de la cadena que t� el node apuntat per m
       com a primer, u apunta a l'�ltim node, a �s o b� NULL si oact
       no apunta a cap node de la cadena que comen�a amb m o b� apunta
       al node c�pia del node apuntat per oact */

void erase_list(node_llista *n){
	if(n != NULL){
		erase_list(n->seg);
		delete n;
		n = NULL;
	}
}
Llista& operator=(const Llista& original){
	if (this != &original){
		longitud = original.longitud;
		erase_list(this->primer_node);
		primer_node = copia_node_llista_it(original.primer_node, original.act, ultim_node, act);
	}
	return *this;
}
    /* Pre: cert */
    /* Post: El p.i. passa a ser una c�pia d'original i qualsevol
       contingut anterior del p.i. ha estat esborrat (excepte si el
       p.i. i original ja eren el mateix objecte) */
