/* template for plugins */
#include <glib.h>
#include <gmodule.h>

gchar *g_module_check_init(){
/* 
  load all symbols,
  return NULL on success,
  error string on fail
  can be used like plugin_main()
*/
}

void g_module_unload(){
/*unload all symbols, then g*/
}
