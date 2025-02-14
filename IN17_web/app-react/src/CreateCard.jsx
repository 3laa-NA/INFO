import { useState } from 'react'
import './App.css'

function CreateCard({ onSubmit }) {
    const [symbol, setSymbol] = useState('')

    const handleSubmit = (e) => {
        e.preventDefault()
        onSubmit({
            symbol: symbol,
            affichage: 'hidden'
        })
        setSymbol('')
    }

    return (
        <form onSubmit={handleSubmit} className="create-card-form">
            <div>
                <label htmlFor="symbol">Symbole:</label>
                <input
                    type="text"
                    id="symbol"
                    value={symbol}
                    onChange={(e) => setSymbol(e.target.value)}
                    required
                />
            </div>
²            <button type="submit">Créer la carte</button>
        </form>
    )
}

export default CreateCard
