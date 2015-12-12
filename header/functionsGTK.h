/* 
 * File:   FunctionsGTK.h
 * Author: pierre
 *
 * Created on 10 décembre 2015, 19:27
 */

#ifndef FUNCTIONSGTK_H
#define	FUNCTIONSGTK_H
#include <gtk/gtk.h>

#ifdef	__cplusplus
extern "C" {
#endif

    GtkWidget* buildButtonQuit(GtkBuilder *builder);
    GtkWidget* buildButtonRun(GtkBuilder *builder);
    GtkWidget* initLabel(GtkBuilder *builder, char *str,char *name);
    void setLabel(GtkWidget* label, char *str);


#ifdef	__cplusplus
}
#endif

#endif	/* FUNCTIONSGTK_H */

