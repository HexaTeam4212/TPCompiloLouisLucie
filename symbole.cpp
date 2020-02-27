

void Symbole::Affiche() {
   cout<<Etiquettes[ident];
}

bool Symbole::isTerminal() {
    if (Etiquettes[this->ident] == "EXPR")
        return false;
    else if (Etiquettes[this->ident] == "ERREUR") {
        cout << "erreur symbole" << endl;
        return false;
    }
    else
        return true;
}

int Symbole::getValeur() {
    return -1;
}

void Entier::Affiche() {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
}

int Entier::getValeur() {
    return valeur;
}

