//#include <gtk-2.0/gtk/gtkstyle.h>

#include "../header/functionsGTK.h"

GtkWidget* buildButtonQuit(GtkBuilder *builder) {
    //GtkWidget *button = (GtkWidget*)malloc(sizeof(GtkWidget));
    GtkWidget *button;

    button = GTK_WIDGET(gtk_builder_get_object(builder, "ButtonQuit"));
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(gtk_main_quit), NULL);

    return button;
}

GtkWidget* buildButtonRun(GtkBuilder *builder) {
    GtkWidget *button;

    button = GTK_WIDGET(gtk_builder_get_object(builder, "ButtonRun"));

    return button;
}

GtkWidget* initLabel(GtkBuilder *builder, char *str, char *name) {
    GtkWidget *label;
    
    label = GTK_WIDGET(gtk_builder_get_object(builder, name));
    gtk_label_set_text(GTK_LABEL(label), str);

    return label;
}

void setLabel(GtkWidget* label, char *str){
    gtk_label_set_text(GTK_LABEL(label), str);
}

