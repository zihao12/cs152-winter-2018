#include <stdlib.h>
#include <stdio.h>
#include "adrbook.h"

const char *_vcard_todo_format = "TODO [vcard]: %s\nhalting\n";

/* vcard_new : allocate a new vcard, copy all strings, return new object
 * note: this is a "deep copy" as opposed to a "shallow copy"; the string 
 *   arguments are not to be shared by the newly allocated vcard
 */
vcard* vcard_new(const char* cnet, const char* email, 
                 const char* fname, const char* lname, const char* tel)
{
  vcard* v = calloc(1,sizeof(vcard));
  v->cnet = strdup(cnet);
  v->email = strdup(email);
  v->fname = strdup(fname);
  v->lname = strdup(lname);
  v->tel = strdup(tel);
  return v;
}

/* vcard_free : free vcard and the strings it points to
 */
void vcard_free(vcard* vc)
{
  free(vc->cnet);
  free(vc->email);
  free(vc->fname);
  free(vc->lname);
  free(vc->tel);
}

void vcard_show(FILE* f, vcard* vc)
{
	if (!vc){
		fprintf(f,"cannot show empty vcard\n");
  		exit(1);
	}
	fprintf(f, "cnet: %s\n", vc->cnet);
	fprintf(f,"email: %s\n",vc->email);
	fprintf(f,"fname: %s\n",vc->fname);
	fprintf(f,"lname: %s\n",vc->lname);
	fprintf(f,"tel: %s\n",vc->tel);
}
