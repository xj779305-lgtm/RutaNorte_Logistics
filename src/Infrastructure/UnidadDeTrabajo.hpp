#include "../Application/IUnidadDeTrabajo.hpp"

// Versión mínima: solo lleva la cuenta de commits y rollbacks.
class UnidadDeTrabajoEnMemoria : public IUnidadDeTrabajo {
public:
    void iniciar() override {}
    void confirmar() override { ++commits; }
    void revertir() override { ++rollbacks; }
    int commits = 0;
    int rollbacks = 0;
};
