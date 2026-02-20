pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
                echo "Build running..."
            }
        }
    }

    post {
        success {
            emailext(
                to: 'maneesha9391@gmail.com',
                subject: "Build Success: ${env.JOB_NAME}",
                body: "Build completed successfully",
                attachLog: true
            )
        }

        failure {
            emailext(
                to: 'maneesha9391@gmail.com',
                subject: "Build Failed: ${env.JOB_NAME}",
                body: "Build failed. Check attached log",
                attachLog: true
            )
        }
    }
}
