#include <stdio.h>
#include <stdlib.h>
typedef struct t_data {
    int size;
    int * ptr;
} DATA;
void create_data(DATA *z, int sz)
{
    int * t;
    int i;
    z->size = sz;
    z->ptr = (int *) malloc(sz*sizeof(int));
    t = z->ptr;
    for (i=0; i< sz; i++)  {
        t[i] = i;
    }
}
void show_data(DATA d)		// d = x; d.size = x.size; d.ptr = x.ptr;
{
    int i;
    printf("%u\n", sizeof(d));
    for (i=0; i<d.size; i++) {
        printf("%d ", (d.ptr)[i]);		// (d.ptr)[i] = *(d.ptr + i)		// �q d.ptr �}�Y��m�첾 i �Ӧ�m 
        if ((i+1)%10 == 0) printf("\n");
    }
}
void delete_data(DATA *z)
{
    free(z->ptr);
    z->ptr = NULL;
    z->size = 0;
}
DATA clone_data(DATA x)
{
    int i;
    DATA y;
    y.size = x.size;
    y.ptr = (int *) malloc(y.size*sizeof(int));		// ���MDATA x ���P���Ŷ� 
    for (i=0; i<y.size; i++) {
        (y.ptr)[i] = (x.ptr)[i];		// �A��DATA x�o���e�ƻs��DATA y 
    }
    return y;
}

int main(void)
{
    DATA x = {0,NULL}, x_clone = {0,NULL};
    create_data(&x, 100);
    show_data(x);
    //x_clone = x;		// ��DATA x �̭�����ƽƻs�� DATA x_clone (�s���V��ptr���@��) 
	
	//��DATA x �̭�����ƶǶiDATA x_clone �����V���P����m 
    x_clone = clone_data(x);		//point
    delete_data(&x);
    show_data(x_clone);

    return 0;
}


//�令show data �ǫ��жi�h 
#include <stdio.h>
#include <stdlib.h>
typedef struct t_data {
    int size;
    int * ptr;
} DATA;
void create_data(DATA *z, int sz)
{
    int * t;
    int i;
    z->size = sz;
    z->ptr = (int *) malloc(sz*sizeof(int));
    t = z->ptr;
    for (i=0; i< sz; i++)  {
        t[i] = i;
    }
}
void show_data(DATA * d)		
{
    int i;

    for (i=0; i<d->size; i++) {
        printf("%d ", (d->ptr)[i]);		 		// Point
        if ((i+1)%10 == 0) printf("\n");
    }
}
void delete_data(DATA *z)
{
    free(z->ptr);
    z->ptr = NULL;
    z->size = 0;
}
DATA clone_data(DATA x)
{
    int i;
    DATA y;
    y.size = x.size;
    y.ptr = (int *) malloc(y.size*sizeof(int));
    for (i=0; i<y.size; i++) {
        (y.ptr)[i] = (x.ptr)[i];
    }
    return y;
}

int main(void)
{
    DATA x , x_clone;
    create_data(&x, 100);
    show_data(&x);		//�Ǧ�m 
    x_clone = clone_data(x);
    delete_data(&x);
    show_data(x_clone);

    return 0;
}








//�令clone_data(&x_clone,&x);
#include <stdio.h>
#include <stdlib.h>
typedef struct t_data {
    int size;
    int * ptr;
} DATA;
void create_data(DATA *z, int sz)
{
    int * t;
    int i;
    z->size = sz;
    z->ptr = (int *) malloc(sz*sizeof(int));
    t = z->ptr;
    for (i=0; i< sz; i++)  {
        t[i] = i;
    }
}
void show_data(DATA d)		// d = x; d.size = x.size; d.ptr = x.ptr;
{
    int i;
    printf("%u\n", sizeof(d));
    
    for (i=0; i<d.size; i++) {
        printf("%d ", (d.ptr)[i]);		// (d.ptr)[i] = *(d.ptr + i)		// �q d.ptr �}�Y��m�첾 i �Ӧ�m 
        if ((i+1)%10 == 0) printf("\n");
    }
}
void delete_data(DATA *z)
{
    free(z->ptr);
    z->ptr = NULL;
    z->size = 0;
}
void clone_data(DATA * pxc, const DATA *px)
{
    int i;
    pxc-> = px->size;
    
    if(pxc->ptr != NULL) free(pxc->ptr);		// �ˬd�����Ŷ��i���i�H�� 
    pxc->ptr = (int *)malloc(pxc->size * sizeof(int));
    
    for (i=0; i<pxc->size; i++) {
        (pxc->ptr)[i] = (px->ptr)[i];		// �A��DATA x�o���e�ƻs��DATA y 
    }
    return y;
}

int main(void)
{
    DATA x , x_clone;
    create_data(&x, 100);
    show_data(x);

	clone_data(&x_clone,&x);
    delete_data(&x);
    
	show_data(x);
    show_data(x_clone);

    return 0;
}
