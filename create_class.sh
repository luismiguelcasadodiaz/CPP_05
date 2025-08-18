#!/usr/bin/bash
sed 's/${CLASS_NAME}/'$1'/g' canonical_class_template.hpp |tee $1.class.hpp
sed 's/${CLASS_NAME}/'$1'/g' canonical_class_template.cpp |tee $1.class.cpp
c++ -std=c++98 -Werror -Wall -Wextra -c $1.class.cpp
# Ahora, verificamos el código de salida del comando anterior
if [ $? -eq 0 ]; then
    echo "¡La compilación fue exitosa! "
	rm $1.class.o
else
    echo "Hubo un error de compilación. revisa la plantillas canonica."
fi

