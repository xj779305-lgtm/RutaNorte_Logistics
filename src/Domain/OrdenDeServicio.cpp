#include "OrdenDeServicio.hpp"
#include "Errores.hpp"

OrdenDeServicio::OrdenDeServicio(std::string numero) : numero_(std::move(numero)) {
    bitacora_.push_back("OrdenDeServicioGenerada");
}

void OrdenDeServicio::avanzarA(EstatusDelServicio nuevo, const std::string& evento) {
    // Solo se avanza al siguiente estatus de G-16 y una orden detenida no avanza.
    if (detenida_ || static_cast<int>(nuevo) != static_cast<int>(estatus_) + 1)
        throw TransicionDeEstatusInvalida();
    estatus_ = nuevo;
    bitacora_.push_back(evento);
}

void OrdenDeServicio::registrarRecoleccion()     { avanzarA(EstatusDelServicio::Recolectado, "MercanciaRecolectada"); }
void OrdenDeServicio::iniciarTraslado()          { avanzarA(EstatusDelServicio::EnTransito, "TrasladoIniciado"); }
void OrdenDeServicio::registrarLlegadaADestino() { avanzarA(EstatusDelServicio::LlegadaADestino, "LlegadaADestino"); }

void OrdenDeServicio::rechazarMercancia(const std::string& tipoDeDiscrepancia, int cantidadDeFotos) {
    if (estatus_ != EstatusDelServicio::UnidadAsignada || detenida_) throw TransicionDeEstatusInvalida();
    if (tipoDeDiscrepancia.empty() || cantidadDeFotos <= 0) throw EvidenciaIncompleta();  // US-09: adjunta fotos
    detenida_ = true;
    bitacora_.push_back("MercanciaRechazada (" + tipoDeDiscrepancia + ")");
}

void OrdenDeServicio::registrarEntrega(const EvidenciaDeEntrega& evidencia) {
    if (estatus_ != EstatusDelServicio::LlegadaADestino) throw TransicionDeEstatusInvalida();
    if (!evidencia.estaCompleta()) throw EvidenciaIncompleta();     // RN-03, CE-03
    evidencia_ = evidencia;
    avanzarA(EstatusDelServicio::Entregado, "EntregaRealizada");
}
