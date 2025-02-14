import { useState } from 'react'

function Login({ onLogin }) {
    const [credentials, setCredentials] = useState({
        username: '',
        password: ''
    })

    const handleSubmit = (e) => {
        e.preventDefault()
        onLogin()
    }

    const handleChange = (e) => {
        setCredentials({
            ...credentials,
            [e.target.name]: e.target.value
        })
    }

    return (
        <form onSubmit={handleSubmit}>
            <div>
                <label htmlFor="username">Login:</label>
                <input
                    type="text"
                    id="username"
                    name="username"
                    value={credentials.username}
                    onChange={handleChange}
                    required
                />
            </div>
            <div>
                <label htmlFor="password">Mot de passe:</label>
                <input
                    type="password"
                    id="password"
                    name="password"
                    value={credentials.password}
                    onChange={handleChange}
                    required
                />
            </div>
            <button type="submit">Se connecter</button>
        </form>
    )
}

export default Login
