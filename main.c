#include <gtk/gtk.h>

void load_builder(gchar *filename){
  GtkBuilder *ui=gtk_builder_new();
  gtk_builder_add_from_file(ui, filename, NULL);
  /* gtk_builder_set_translation_domain(ui, filename); TODO remove .ui from filename*/
  GSList *objects=gtk_builder_get_objects(ui);
  gtk_widget_show_all(objects->data);
  /* TODO watch filename to gtk_widget_destroy(objects->data) if it is deleted */
  gtk_builder_connect_signals(ui); /* TODO *_full? for interpreted lang plugins */
  g_object_unref(G_OBJECT(ui));
  g_slist_free(objects);
}

void load_module(gchar *filename){
  g_module_open(filename, G_MODULE_BIND_LAZY);
  /* TODO watch to g_module_unload() && g_module_close() it */
}

void add_icon(gchar *filename){
  /* TODO */
}

void remove_icon(gchar *filename){
  /* TODO */
}


void handle_file(gchar *file, GFileMonitorEvent event_type){
if (event_type == G_FILE_MONITOR_EVENT_CHANGED || event_type == G_FILE_MONITOR_EVENT_DELETED){
  if (g_str_has_suffix(const gchar *str, ".desktop")) remove_icon(file);
}
if (event_type == G_FILE_MONITOR_EVENT_CHANGED || event_type == G_FILE_MONITOR_EVENT_CREATED){
  if (g_str_has_suffix(const gchar *str, ".so")) load_module(file);
  if (g_str_has_suffix(const gchar *str, ".ui")) load_builder(file);
  if (g_str_has_suffix(const gchar *str, ".desktop")) add_icon(file);
}
}

void on_changed(
  GFileMonitor  *monitor,
  GFile *file,
  GFile *other_file,
  GFileMonitorEvent event_type,
  gpointer user_data){
#ifdef DEBUG
  g_print ("File = %s\nOther File = %s\n",g_file_get_parse_name(file),g_file_get_parse_name(other_file));
#endif
handle_file(file,event_type);
}

int main(int argc, char **argv){
  gtk_init(&argc, &argv);
/*load all files already in directory specified by argv[1]*/
  GDir *dir=g_dir_open(argv[1], 0, NULL);
  gchar *file;
  while (file=g_dir_read_name(dir)){
    handle_file(file,G_FILE_MONITOR_EVENT_CREATED);
  }

  g_signal_connect(   /* monitor argv[1] and handle changes with on_changed() */
    g_file_monitor_directory(g_file_new_for_commandline_arg(argv[1]), NULL, NULL, NULL ),
    "changed",G_CALLBACK(on_changed),(gpointer) argv );

}
