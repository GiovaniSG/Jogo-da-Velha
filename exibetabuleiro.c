void exibeTabuleiro(int tabuleiro[][DIM])
{
    int linha, coluna;
    putchar('\n');

    for(linha = 0 ; linha < DIM ; linha++)
    {
        for(coluna = 0 ; coluna < DIM ; coluna++)
        {
            if(tabuleiro[linha][coluna] == 0)
                printf("    ");
            else
                if(tabuleiro[linha][coluna] == 1)
                    printf("  X ");
                else
                    printf("  O ");

            if(coluna != (DIM-1))
                printf("|");
        }
        putchar('\n');
    }
    putchar('\n');
}
