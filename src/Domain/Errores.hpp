#include <stdexcept>

struct EvidenciaIncompleta : std::runtime_error {          // RN-03, CE-03
    EvidenciaIncompleta() : std::runtime_error("EvidenciaIncompleta") {}
};
struct TransicionDeEstatusInvalida : std::runtime_error {  // G-16
    TransicionDeEstatusInvalida() : std::runtime_error("TransicionDeEstatusInvalida") {}
};
struct OrdenNoEncontrada : std::runtime_error {
    OrdenNoEncontrada() : std::runtime_error("OrdenNoEncontrada") {}
};
