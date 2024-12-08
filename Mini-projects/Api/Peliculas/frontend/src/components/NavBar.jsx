export default function NavBar() {
    return (
        <nav className="navbar navbar-expand-lg navbar-light bg-light">
            <div className="container-fluid">
                <a className="navbar-brand" href="#">
                    API PELICULAS - FRONTEND
                </a>
                <button
                    className="navbar-toggler"
                    type="button"
                    data-bs-toggle="collapse"
                    data-bs-target="#navbarNav"
                    aria-controls="navbarNav"
                    aria-expanded="false"
                    aria-label="Toggle navigation"
                >
                    <span className="navbar-toggler-icon" />
                </button>
                <div className="collapse navbar-collapse" id="navbarNav">
                    <ul className="navbar-nav">
                        <li className="nav-item">
                            <a className="nav-link active" aria-current="page" href="#">
                                Inicio
                            </a>
                        </li>
                        <li className="nav-item">
                            <a className="nav-link" href="#">
                                Películas
                            </a>
                        </li>
                        <li className="nav-item">
                            <a className="nav-link" href="#">
                                Directores
                            </a>
                        </li>
                        <li className="nav-item">
                            <a className="nav-link" href="#">
                                Actores
                            </a>
                        </li>
                    </ul>
                </div>
            </div>
        </nav>
    );
}