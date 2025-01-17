#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_list_size(t_list *begin_list)
{
	int i = 0;
	while(begin_list)
	{
		i++;
		begin_list = begin_list->next;
	}
	return i;
}
/*
la función ft_list_size(t_list *begin_list) no modifica el valor de *begin_list.

La función solo recorre la lista, aumentando el contador i mientras avanza de nodo en nodo. El puntero begin_list es solo utilizado como referencia para empezar a recorrer la lista, pero no se cambia su valor dentro de la función.

Esto es porque la función recibe un puntero simple (t_list *begin_list), no un doble puntero (t_list **begin_list), por lo que los cambios que realices dentro de la función no afectarán al valor original de begin_list en la función que la llama.
*/

t_list *create_struct(char *data)
{
	t_list *new_element = malloc(sizeof(t_list));
	if(!new_element)
		return NULL;
	new_element->data = data;
	new_element->next = NULL;
	return new_element;
}

void	destroy_struct(t_list *element)
{
	free(element);
}

void	insert_begin(t_list **begin_list, char *data)//por que **begin_list?
/*begin_list es una etiqueta que apunta a una caja llamada "primer nodo". Cuando pasas *begin_list a la función, lo que estás diciendo es: Aquí tienes una copia de mi etiqueta, pero si cambias a qué caja apunta, el puntero original fuera de la función no se entera. Si pasas *begin_list (un puntero simple) a la función, cualquier cambio que hagas en la dirección de memoria que ese puntero apunta no afecta al puntero original fuera de la función. Solo estás trabajando con una copia. Para que el puntero original fuera de la función sí se entere de los cambios, debes pasar su dirección (es decir, un doble puntero **begin_list). Aquí estás diciendo: "Toma mi etiqueta original, y si decides cambiar a qué caja apunta, hazlo directamente sobre mi etiqueta, no sobre una copia". Cuando usas *begin_list = Element0;, estás diciendo: "Cambia la caja original que mi etiqueta señala para que apunte a Element0". Así te aseguras que el cambio se refleje fuera de la función.
*/
{
	t_list *element = create_struct(data); //la función ft_list_size(t_list *begin_list) no modifica el valor de *begin_list. La función solo recorre la lista, aumentando el contador i mientras avanza de nodo en nodo. El puntero begin_list es solo utilizado como referencia para empezar a recorrer la lista, pero no se cambia su valor dentro de la función. Esto es porque la función recibe un puntero simple (t_list *begin_list), no un doble puntero (t_list **begin_list), por lo que los cambios que realices dentro de la función no afectarán al valor original de begin_list en la función que la llama.
	element->next = *begin_list;
	*begin_list = element;
}

void	insert_end(t_list **begin_list, char *data)
{
	t_list *element = create_struct(data);
	if(*begin_list == NULL)
		*begin_list = element;
	else
	{
		t_list *pointer = *begin_list;//creo un puntero temporal para que begin_list conserve la referencia al inicio de la lista para no perderla fuera de la función.
		while(pointer->next)

			pointer = pointer->next;//Los parentesis se usan para desreferenciar *begin_list, el puntero doble begin_list y accede al puntero t_list * al que apunta. (*begin_list)->next accede al campo next del nodo al que apunta *begin_list. Sin los parentesis, la expresión *begin_list->next se evalúa de manera incorrecta debido a la precedencia de los operadores. En este caso, el operador -> tiene mayor precedencia que el operador *
		pointer->next = element;
	}
}

void	delete_begin(t_list **begin_list)
{
	if(*begin_list != NULL)
	{
		t_list *delete = *begin_list;
		*begin_list = (*begin_list)->next;
		destroy_struct(delete);
	}
}
void	delete_end(t_list **begin_list)
{
	if(*begin_list != NULL)
	{
		t_list *pointer = *begin_list;//creo un puntero temporal para que begin_list conserve la referencia al inicio de la lista para no perderla fuera de la función.
		while(pointer->next->next)
			pointer = pointer->next;
		destroy_struct(pointer->next);
		pointer->next = NULL;
	}
}

int	main()
{
	t_list *Element1 = create_struct("First element in the list");
	t_list *Element2 = create_struct("Second element in the list");
	t_list *Element3 = create_struct("Third element in the list");
	
	t_list *begin_list = Element1;
	Element1->next = Element2;
	Element2->next = Element3;
	
	insert_begin(&begin_list, "New first element in the list");
	/*
	Si eliminas el & en la línea:
	insert_begin(&begin_list, "New first element in the list");
	y escribes:
	insert_begin(begin_list, "New first element in the list");
	pasarías un puntero simple (un puntero a t_list) en lugar de un doble puntero. Esto significa que no podrías modificar el puntero original begin_list fuera de la función. El cambio que harías dentro de insert_begin no afectaría al puntero de main, y el primer nodo de la lista no se actualizaría. Con &begin_list: Puedes modificar el puntero original en main, ya que pasas la dirección de begin_list.
	*/
	
	int count = ft_list_size(begin_list);
	printf("%i\n", count);
	
	t_list *temp = begin_list;
	while (temp) 
	{
   		printf("%s\n", (char *)temp->data);
    		temp = temp->next;
    	}
    	
    	delete_begin(&begin_list);
    	delete_end(&begin_list);
    	
    	count = ft_list_size(begin_list);
	printf("%i\n", count);
	
	temp = begin_list;
	while (temp) 
	{
   		printf("%s\n", (char *)temp->data);
    		temp = temp->next;
    	}
	
	destroy_struct(Element1);
	destroy_struct(Element2);
	//destroy_struct(Element3); No puedo destruirlo otra vez porque el elemento 3 es el ultimo y ha sido destruido con la llamada delete_end.

	return 0;
}
