pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
                echo 'Building project...'
            }
        }
    }

    post {
        success {
            emailext (
                to: 'maneesha9391@gmail.com',
                subject: "✅ Build SUCCESS: ${env.JOB_NAME} #${env.BUILD_NUMBER}",
                body: """
                Build Successful!

                Job Name: ${env.JOB_NAME}
                Build Number: ${env.BUILD_NUMBER}
                Build URL: ${env.BUILD_URL}
                """,
                attachLog: true
            )
        }

        failure {
            emailext (
                to: 'maneesha9391@gmail.com',
                subject: "❌ Build FAILED: ${env.JOB_NAME} #${env.BUILD_NUMBER}",
                body: """
                Build Failed!

                Job Name: ${env.JOB_NAME}
                Build Number: ${env.BUILD_NUMBER}
                Check Console Output: ${env.BUILD_URL}
                """,
                attachLog: true
            )
        }
    }
}
