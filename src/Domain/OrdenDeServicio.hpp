#include <optional>
#include <string>
#include <vector>
#include "EstatusDelServicio.hpp"
#include "EvidenciaDeEntrega.hpp"

class OrdenDeServicio {
public:
    explicit OrdenDeServicio(std::string numero);

    void registrarRecoleccion();
    void iniciarTraslado();
    void registrarLlegadaADestino();
    void rechazarMercancia(const std::string& tipoDeDiscrepancia, int cantidadDeFotos);  // CU-03
    void registrarEntrega(const EvidenciaDeEntrega& evidencia);                          // CU-04

    const std::string& numero() const { return numero_; }
    EstatusDelServicio estatus() const { return estatus_; }
    bool estaDetenida() const { return detenida_; }
    const std::vector<std::string>& bitacora() const { return bitacora_; }

private:
    void avanzarA(EstatusDelServicio nuevo, const std::string& evento);

    std::string numero_;
    EstatusDelServicio estatus_ = EstatusDelServicio::UnidadAsignada;
    bool detenida_ = false;
    std::optional<EvidenciaDeEntrega> evidencia_;
    std::vector<std::string> bitacora_;
};
