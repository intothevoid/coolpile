/* Grammar
 *
 * E-> T|T+E
 * T-> int|int*T|(E)
 */

bool term(TOKEN tok) { return *next++ == tok; }

bool E1() { return T(); }
bool E2() { return T() && term(PLUS) && E(); }

bool E()
{
    TOKEN* save = next;
    return ((next = save, E1()) || (next = save, E2()));
}

bool T1() { return term(INT); }
bool T2() { return term(INT) && term(TIMES) && T(); }
bool T3() { return term(OPEN) && E() && term(CLOSE); }

bool T()
{
    TOKEN* save = next;
    return ((next = save), T1() || (next = save),T2() || (next = save),T3());
}

