#include <gtk/gtk.h>

/* Función que maneja el clic en el botón */
static void on_button_clicked(GtkWidget *widget, gpointer data) {
    gtk_main_quit();  // Termina el programa cuando el botón es clickeado
}

/* Crea la ventana principal y el botón */
static GtkWidget* create_main_window() {
    GtkWidget *window;
    GtkWidget *button;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Ventana principal");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 200);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    button = gtk_button_new_with_label("Manuel Giovanni Cortazar De La Cruz");
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), NULL);

    gtk_container_add(GTK_CONTAINER(window), button);

    return window;
}

/* Inicializa y ejecuta la aplicación GTK */
int main(int argc, char *argv[]) {
    GtkWidget *window;

    gtk_init(&argc, &argv);  // Inicializa GTK

    window = create_main_window();  // Crea la ventana y el botón

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);  // Muestra todos los widgets en la ventana

    gtk_main();  // Entra en el bucle principal de GTK

    return 0;
}
