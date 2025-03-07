# Module CMake pour la gestion complète de Doxygen

# Rechercher l'exécutable Doxygen
find_program(DOXYGEN_EXECUTABLE doxygen)

if(DOXYGEN_EXECUTABLE)
    if (SHOW_DEBUG_MESSAGES)
      message(STATUS "Doxygen trouvé à ${DOXYGEN_EXECUTABLE}")
    endif()

    # Vérification que Doxygen est bien installé
    set(DOXYGEN_FOUND TRUE)

    # Variables de configuration
    set(DOXYGEN_INPUT "${CMAKE_SOURCE_DIR}/src")  # Répertoires d'entrée (par défaut)
    set(DOXYGEN_OUTPUT_DIR "${CMAKE_BINARY_DIR}/docs")  # Répertoire de sortie (par défaut)
    set(DOXYGEN_FILE_PATTERNS "*.c *.h")  # Types de fichiers à inclure
    set(DOXYGEN_GENERATE_LATEX NO)  # Ne pas générer de LaTeX (par défaut)
    set(DOXYGEN_GENERATE_HTML YES)  # Générer de l'HTML (par défaut)
    set(GENERATE_TREEVIEW YES)  # Générer un arbre de navigation (par défaut)
    set(DOXYGEN_EXTRACT_ALL YES)  # Extraire toute la documentation (par défaut)
    if (SHOW_DEBUG_MESSAGES)
        set(DOXYGEN_QUIET NO)  # Mode verbeux
    else()
        set(DOXYGEN_QUIET YES)  # Mode silencieux (par défaut)
    endif()

    # Configuration du fichier Doxyfile à partir d'un modèle
    configure_file(
        "${CMAKE_SOURCE_DIR}/docs/Doxyfile.in"
        "${CMAKE_BINARY_DIR}/Doxyfile"
        @ONLY
    )

    # Ajout d'une cible pour générer la documentation
    add_custom_target(
        docs
        COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_BINARY_DIR}/Doxyfile
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMENT "Génération de la documentation avec Doxygen"
    )

    message(STATUS "La documentation peut être générée avec la cible 'docs'.")

else()
    message(WARNING "Doxygen non trouvé, la génération de la documentation est désactivée.")
    set(DOXYGEN_FOUND FALSE)
endif()
