import { useState } from 'react'

function FormulaireAjout({ onAjoutLivre }) {
  const [nouveauLivre, setNouveauLivre] = useState({
    auteur: '',
    titre: '',
    cote: ''
  })

  const handleFormChange = (e) => {
    const { name, value } = e.target
    setNouveauLivre(prev => ({
      ...prev,
      [name]: value
    }))
  }

  const handleSubmit = (e) => {
    e.preventDefault()
    if (nouveauLivre.auteur && nouveauLivre.titre && nouveauLivre.cote) {
      onAjoutLivre({
        ...nouveauLivre,
        emprunt: { statut: false, dateEmprunt: new Date() }
      })
      // Réinitialisation du formulaire
      setNouveauLivre({
        auteur: '',
        titre: '',
        cote: ''
      })
    }
  }

  return (
    <form onSubmit={handleSubmit} className="nouveau-livre-form">
      <div>
        <input
          type="text"
          name="auteur"
          value={nouveauLivre.auteur}
          onChange={handleFormChange}
          placeholder="Auteur"
          required
        />
      </div>
      <div>
        <input
          type="text"
          name="titre"
          value={nouveauLivre.titre}
          onChange={handleFormChange}
          placeholder="Titre"
          required
        />
      </div>
      <div>
        <input
          type="text"
          name="cote"
          value={nouveauLivre.cote}
          onChange={handleFormChange}
          placeholder="Cote"
          required
        />
      </div>
      <button type="submit">Ajouter le livre</button>
    </form>
  )
}

export default FormulaireAjout
