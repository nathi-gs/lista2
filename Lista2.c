for (i = 0; i < 2 - 1; i++) {
        for (j = 0; j < 2 - i - 1; j++) {
            if (strcmp(estudante[j].nome, professor[j + 1].nome) > 0) {
                struct Professor temp = professor[j];
                professor[j] = professor[j + 1];
                professor[j + 1] = temp;
            }
        }
    }
