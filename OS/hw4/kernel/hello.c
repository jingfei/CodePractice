#include <linux/module.h>
static char *msg = "";
module_param(msg, charp, S_IRUGO);
int init_func(void)
{
	printk("Hello world ! %s \n", msg);
	return 0;
}
void cleanup_func(void)
{
	printk("Goodbye world !\n");
}
module_init(init_func);
module_exit(cleanup_func);
