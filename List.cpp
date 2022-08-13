/*
 * List.cpp
 *
 *  Created on: 18/7/2021 (v15)
 *      Author: Matheus Oliveira Ribeiro da Silva
 */
#include "List.h"

//---------------------------------------------------------------
List::List()
{
  head = NULL;
  count = 0;
}
//---------------------------------------------------------------
List::~List()
{
  clear();
}
//---------------------------------------------------------------
bool List::empty()
{
  return (head == NULL);
}
//---------------------------------------------------------------
bool List::full()
{
   return false;
}
//---------------------------------------------------------------
void List::clear()
{ ListPointer q;

  while (head != NULL)
  {  q = head;
     head = head->nextNode;
     delete q;
  }
  count = 0;
}
//---------------------------------------------------------------
long List::size()
{
   return count;
}
//---------------------------------------------------------------
void List::insert(long p, ListEntry x)
{ ListPointer newNode, current;

  if (p < 1 || p > count+1)
  { cout << "Posicao invalida" << endl;
    abort();
  }
  newNode = new ListNode;
  newNode->entry = x;
  if(p == 1)
  {  newNode->nextNode = head;
     head = newNode;
  }
  else
  {  setPosition(p-1,current);
     newNode->nextNode = current->nextNode;
     current->nextNode = newNode;
  }
  count++;
}
//---------------------------------------------------------------
void List::remove(long p, ListEntry &x)
{ ListPointer node, current;

  if (p < 1 || p > count)
  { cout << "Posicao invalida" << endl;
    abort();
  }
  if(p == 1)
  {  node = head;
     head = node->nextNode;
  }
  else
  {  setPosition(p-1,current);
     node = current->nextNode;
     current->nextNode = node->nextNode;
  }
  x = node->entry;
  delete node;
  count = count - 1;
}
//---------------------------------------------------------------
void List::retrieve(long p, ListEntry &x)
{ ListPointer current;

  if (p < 1 || p > count)
  { cout << "Posicao invalida" << endl;
    abort();
  }
  setPosition(p,current);
  x = current->entry;
}
//---------------------------------------------------------------
long List::search(ListEntry x)
{ long p=1;
  ListPointer q=head;

  while (q != NULL && q->entry != x)
  {  q = q->nextNode;
     p++;
  }
  return (q == NULL ? 0 : p);
}
//---------------------------------------------------------------
string List::toString()
{ ListPointer q=head;
  string s;
  stringstream ss;

  while (q != NULL)
  {  ss << q->entry << ",";
     q = q->nextNode;
  }
  s = ss.str();
  return "[" + s.substr(0,s.length()-1) + "]";
}
//---------------------------------------------------------------
string List::toStringAddr()
{ ListPointer q=head;
  string s;
  stringstream ss;

  while (q != NULL)
  {  ss << q << ",";
     q = q->nextNode;
  }
  s = ss.str();
  return "[" + s.substr(0,s.length()-1) + "]";
}
//---------------------------------------------------------------
void List::setPosition(long p, ListPointer &current)
{ long i;

  current = head;
  for(i=2; i<=p; i++)
      current = current->nextNode;
}
//---------------------------------------------------------------
long long List::getAddr(ListEntry x)
{ ListPointer current=NULL;
  long p = search(x);
  if(p != 0)
    setPosition(p, current);
  return (long long)current;
}
//---------------------------------------------------------------
// Pre-Condicao: A lista ja tenha sido criada previamente.
// Pos-Condicao: A funcao retornara TRUE se os dois elementos forem encontrados, e FALSE caso contrario. Pode armazenar em variaveis...
// a posicao e endereco na memoria de cada um, alem do endereco da posicao adjacente (next) a que cada um se encontra.

// metodo auxiliar: busca de dois elementos da lista.
bool List::verificacao(ListEntry a, ListEntry b)
{
long p=1;
	ListPointer q=head;
	
	//ponteiros para armazenar os enderecos dos elementos e da posicao seguinte de cada.
	ListPointer xp;
	ListPointer yp;
	ListPointer nxp;
	ListPointer nyp;

  int x=0; // x armazena a posicao do elemento 'a';
  int y=0; // y armazena a posicao do elemento 'b';
  
  // se os dois forem iguais, nada a fazer.
  if (a==b)
  	return(false);
  	   
  //enquanto o fim da lista nao for alcancado...	   
  while (q != NULL)
  { 
  	//se o elemento 'a' for encontrado, sua posicao na lista sera armazenada em x, seu endereco em xp.
	//de forma analoga para o elemento 'b'.	  
  	if (q->entry == a) {
		x = p;
  		xp = q; //Current
  	} else if (q->entry == b) {
		y = p;
		yp = q;	//Current
	}
	
	//o endereco da proxima posicao (ou NULL (0x0)) ao elemento 'a' sera armazenado em nxp.
	//da mesma forma ao elemento 'b', em nyp. 
	if(p == x+1) {
		nxp = q; //Next
	} else if (p == y+1) {
		nyp = q; //Next
	}	
	
	// a lista eh percorrida no a no e o valor da posicao eh incrementado.
	q = q->nextNode;
    p++;
	}

	// caso os dois valores sejam encontrados, ou seja, as posicoes referentes a 'a' (indicada em x)...
	// e referente a 'b' (indicada em y) nao sao ambas nulas, a funcao retorna 'true'.
  if (x!=0 && y!=0)
  	return(true);
  else
 	return(false);
}
//---------------------------------------------------------------
// Pre-condicao: Lista previamente criada e metodo 'verificacao' pronto para ser acessado;
// Pos-condicao: Se os elementos forem encontrados em 'verificacao', swap ira trocar os nos em que eles se encontram, reposicionando os ponteiros.

bool List::swap(ListEntry a, ListEntry b)
{				

// chamada do metodo auxiliar
verificacao(a, b);

// declaracao dos ponteiros, incluindo um auxiliar (para troca).
ListPointer xp;
ListPointer yp;
ListPointer nxp;
ListPointer nyp;
ListPointer aux;

if (verificacao(a, b) == true){
	// troca dos ponteiros referentes aos elementos (current);
	aux = xp;
	xp = yp;
	yp = aux;
	
	//troca dos ponteiros adjacentes (next)
	aux = nxp;
	nxp = nyp;
	nyp = aux;	
	} else {
		return(false);
	}
}
//---------------------------------------------------------------


