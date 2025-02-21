function Livre({ auteur, titre, emprunt, cote }) {
  return (
    <div className="livre">
      <h3>{titre}</h3>
      <p>Auteur: {auteur}</p>
      <p>Cote: {cote}</p>
      <p>
        Statut: <span className={emprunt.statut ? 'statut-emprunte' : 'statut-disponible'}>
          {emprunt.statut ? 'Emprunté' : 'Disponible'}
        </span>
      </p>
      <p>Date d'emprunt: {emprunt.dateEmprunt.toLocaleDateString()}</p>
    </div>
  )
}

export default Livre
