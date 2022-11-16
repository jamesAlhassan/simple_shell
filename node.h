#ifndef NODE_H
#define NODE_H

/**
 * enum node_type_e - enumerator node
 * @NODE_COMMAND: simple command
 * @NODE_VAR: variable name (or simply a word)
 */
enum node_type_e
{
	NODE_COMMAND,
	NODE_VAR,
};

/**
 *enum val_type_e - enumerator val
 *@VAL_SINT:  signed int
 *@VAL_UINT: unsigned int
 *@VAL_SLLONG: signed long long
 *@VAL_ULLONG: unsigned long long
 *@VAL_FLOAT: floating point
 *@VAL_LDOUBLE: long double
 *@VAL_CHR: char
 *@VAL_STR: str (char pointer)
 */

enum val_type_e
{
	VAL_SINT = 1,
	VAL_UINT,
	VAL_SLLONG,
	VAL_ULLONG,
	VAL_FLOAT,
	VAL_LDOUBLE,
	VAL_CHR,
	VAL_STR,
};


/**
 * union symval_u - union symbol
 * @sint: long
 * @uint: unsigned int
 * @sllong: long long
 * @ullong: unsgned long long
 * @sfloat: double
 * @ldouble: long double
 * @chr: char
 * @str: char
 */

union symval_u
{
	long sint;
	unsigned long uint;
	long long sllong;
	unsigned long long ullong;

	double sfloat;

	long double ldouble;

	char chr;
	char *str;
};


/**
 * struct node_s - struct
 * enum node_type_e type: type of this node
 * 
 */

struct node_s
{
	enum   node_type_e type;    /* type of this node */
	enum   val_type_e val_type; /* type of this node's val field */
	union  symval_u val;        /* value of this node */
	int    children;            /* number of child nodes */
	struct node_s *first_child; /* first child node */
	struct node_s *next_sibling, *prev_sibling;
};

/**
 * struct - struct node
 * @new_node: newww
 *
 */
struct  node_s *new_node(enum node_type_e type);
void    add_child_node(struct node_s *parent, struct node_s *child);
void    free_node_tree(struct node_s *node);
void    set_node_val_str(struct node_s *node, char *val);

#endif
